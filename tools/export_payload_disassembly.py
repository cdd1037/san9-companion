"""Run inside IDA AFTER reconstruct.py; linear decode, no database byte edits."""
from pathlib import Path
import json
import ida_bytes
import ida_lines
import ida_nalt
import ida_ua

from project_paths import PROJECT_ROOT, SOURCE_ROOT
def main():
    if Path(ida_nalt.get_input_file_path()).resolve() != (PROJECT_ROOT / 'recovery/sample-2026/San9PKHard.exe').resolve():
        raise RuntimeError('Wrong IDA input')
    rows = json.loads((SOURCE_ROOT / 'generated/write_catalog.json').read_text(encoding='utf-8'))
    folder = PROJECT_ROOT / 'recovery/evidence/payload_disassembly'
    folder.mkdir(exist_ok=True)
    index, seen = [], set()
    for row in rows:
        if row['status'] != 'static_bytes':
            continue
        source, target, size = row['source_va'], row['target_va'], row['size']
        key = source, target, size
        if key in seen:
            continue
        seen.add(key)
        payload = bytes.fromhex(row['bytes_hex'])
        name = f'{source:08X}_{target:08X}_{size:X}.asm'
        lines = ['; Linear x86 decode of an injected byte-buffer candidate.',
                 '; May contain data, partial instructions, or multiple entrypoints.',
                 '; Not a verified function boundary or an assemblable source file.',
                 f'; Source companion VA=0x{source:08X}; baseline game VA=0x{target:08X}; size={size}',
                 '; Relative branch annotations use the baseline game destination.']
        offset, decoded, undecoded = 0, 0, 0
        while offset < size:
            local = source + offset
            insn = ida_ua.insn_t()
            length = ida_ua.decode_insn(insn, local)
            # Static-initializer-modified data must not be decoded using stale IDA bytes.
            if not length or offset + length > size or ida_bytes.get_bytes(local, length) != payload[offset:offset+length]:
                lines.append(f'{target+offset:08X} [{local:08X}] {payload[offset]:02X}    db 0x{payload[offset]:02X}')
                offset += 1
                undecoded += 1
                continue
            asm = ida_lines.tag_remove(ida_lines.generate_disasm_line(local, ida_lines.GENDSM_FORCE_CODE) or '')
            annotation = ''
            for op in insn.ops:
                if op.type == ida_ua.o_near:
                    annotation += f' ; game-relative-target=0x{(op.addr + target-source)&0xFFFFFFFF:08X}'
            lines.append(f'{target+offset:08X} [{local:08X}] {payload[offset:offset+length].hex(" "):<44} {asm}{annotation}')
            offset += length
            decoded += 1
        (folder / name).write_text('\n'.join(lines) + '\n', encoding='utf-8')
        index.append(dict(source_va=source, target_va=target, size=size, file=name,
                          decoded_instructions=decoded, raw_bytes=undecoded))
    (folder / 'index.json').write_text(json.dumps(index, indent=2) + '\n', encoding='utf-8')
    print(f'Exported {len(index)} linear payload listings')


if __name__ == '__main__':
    main()
