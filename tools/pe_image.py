"""Small PE32 reader for offline reconstruction; Python standard library only."""
from pathlib import Path
import struct


class PEImage:
    def __init__(self, path):
        self.path = Path(path)
        self.raw = self.path.read_bytes()
        if self.raw[:2] != b'MZ':
            raise ValueError('Not an MZ file')
        pe = self.u32(0x3C)
        if self.raw[pe:pe + 4] != b'PE\0\0':
            raise ValueError('Not a PE file')
        self.machine, count, self.timestamp = struct.unpack_from('<HHI', self.raw, pe + 4)
        optional_size = self.u16(pe + 20)
        opt = pe + 24
        if self.machine != 0x14C or self.u16(opt) != 0x10B:
            raise ValueError('This project requires the x86 PE32 sample')
        self.base = self.u32(opt + 28)
        self.entry = self.base + self.u32(opt + 16)
        self.size = self.u32(opt + 56)
        self.header_size = self.u32(opt + 60)
        self.directories = [struct.unpack_from('<II', self.raw, opt + 96 + 8*i)
                            for i in range(min(16, self.u32(opt + 92)))]
        self.sections = []
        self.memory = bytearray(self.size)
        self.memory[:self.header_size] = self.raw[:self.header_size]
        for i in range(count):
            offset = opt + optional_size + i*40
            name = self.raw[offset:offset + 8].rstrip(b'\0').decode('ascii')
            vs, rva, size, pointer = struct.unpack_from('<IIII', self.raw, offset + 8)
            flags = self.u32(offset + 36)
            if pointer + size > len(self.raw) or rva + max(vs, size) > self.size:
                raise ValueError('Section exceeds file/image')
            self.sections.append(dict(name=name, va=self.base + rva, rva=rva,
                                      virtual_size=vs, raw_size=size, raw_offset=pointer, flags=flags))
            self.memory[rva:rva + size] = self.raw[pointer:pointer + size]

    def u16(self, offset):
        return struct.unpack_from('<H', self.raw, offset)[0]

    def u32(self, offset):
        return struct.unpack_from('<I', self.raw, offset)[0]

    def offset(self, va, size=1):
        rva = va - self.base
        if not 0 <= rva <= len(self.memory) - size:
            raise ValueError(f'Address outside companion image: 0x{va:X}, size={size}')
        return rva

    def read(self, va, size):
        pos = self.offset(va, size)
        return bytes(self.memory[pos:pos + size])

    def integer(self, va, size=4):
        if size not in (1, 2, 4, 8):
            raise ValueError(f'Unsupported integer width: {size}')
        return int.from_bytes(self.read(va, size), 'little')

    def put32(self, va, value):
        struct.pack_into('<I', self.memory, self.offset(va, 4), value & 0xFFFFFFFF)

    def imported_dlls(self):
        """Read the normal import table without loading or executing the image."""
        rva, size = self.directories[1] if len(self.directories) > 1 else (0, 0)
        if not rva:
            return []
        names = []
        for offset in range(0, size - 19, 20):
            descriptor = struct.unpack('<IIIII', self.read(self.base + rva + offset, 20))
            if not any(descriptor):
                return names
            name_rva = descriptor[3]
            if not name_rva:
                raise ValueError('Import descriptor has no DLL name')
            start = self.offset(self.base + name_rva)
            end = self.memory.find(b'\0', start)
            if end <= start:
                raise ValueError('Empty or unterminated imported DLL name')
            names.append(self.memory[start:end].decode('ascii'))
        raise ValueError('Unterminated import table')

    def resources(self):
        rva, size = self.directories[2]
        if not rva:
            return []
        root = self.base + rva
        found = []

        def walk(relative, keys, seen):
            if relative in seen or len(keys) > 3:
                raise ValueError('Invalid resource tree')
            head = self.read(root + relative, 16)
            named, ids = struct.unpack_from('<HH', head, 12)
            for i in range(named + ids):
                name, child = struct.unpack('<II', self.read(root + relative + 16 + i*8, 8))
                if name & 0x80000000:
                    addr = root + (name & 0x7FFFFFFF)
                    length = self.integer(addr, 2)
                    key = self.read(addr + 2, length*2).decode('utf-16le')
                else:
                    key = name
                if child & 0x80000000:
                    walk(child & 0x7FFFFFFF, keys + [key], seen | {relative})
                else:
                    data_rva, length, codepage, _ = struct.unpack('<IIII', self.read(root + child, 16))
                    found.append(dict(keys=keys + [key], va=self.base + data_rva,
                                      size=length, codepage=codepage,
                                      data=self.read(self.base + data_rva, length)))
        walk(0, [], set())
        return found


def dialog_template(data):
    """Decode standard and extended DLGTEMPLATE without loading it into Windows."""
    pos = 0

    def unpack(fmt):
        nonlocal pos
        result = struct.unpack_from('<' + fmt, data, pos)
        pos += struct.calcsize('<' + fmt)
        return result[0] if len(result) == 1 else result

    def field():
        nonlocal pos
        first = unpack('H')
        if first == 0xFFFF:
            return {'ordinal': unpack('H')}
        if first == 0:
            return ''
        start = pos - 2
        while unpack('H'):
            pass
        return data[start:pos - 2].decode('utf-16le')

    extended = data[:4] == b'\x01\0\xff\xff'
    if extended:
        version, signature, helpid, exstyle, style, count = unpack('HHIIIH')
    else:
        style, exstyle, count = unpack('IIH')
        helpid = 0
    x, y, cx, cy = unpack('hhhh')
    result = dict(extended=extended, help_id=helpid, style=style, exstyle=exstyle,
                  rect=[x,y,cx,cy], menu=field(), window_class=field(), title=field())
    if style & 0x40:
        font = {'point_size': unpack('H')}
        if extended:
            font['weight'], font['italic'], font['charset'] = unpack('HBB')
        font['face'] = field()
        result['font'] = font
    controls = []
    for _ in range(count):
        pos = (pos + 3) & ~3
        if extended:
            helpid, exstyle, style = unpack('III')
        else:
            style, exstyle = unpack('II')
            helpid = 0
        rect = list(unpack('hhhh'))
        ident = unpack('I' if extended else 'H')
        cls, title = field(), field()
        extra_size = unpack('H')
        # Creation-data size includes its own WORD when nonzero.
        extra = data[pos:pos + max(0, extra_size - 2)]
        pos += max(0, extra_size - 2)
        controls.append(dict(id=ident, rect=rect, window_class=cls, title=title,
                             style=style, exstyle=exstyle, help_id=helpid,
                             creation_data=extra.hex()))
    result['controls'] = controls
    result['parsed_size'] = pos
    return result
