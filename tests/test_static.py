from pathlib import Path
import json
import re
import struct
import sys
import unittest

PROJECT_ROOT = Path(__file__).resolve().parents[1]
SOURCE_ROOT = PROJECT_ROOT / 'src'
sys.path.insert(0, str(PROJECT_ROOT / 'tools'))
from pe_image import PEImage, dialog_template
from offline import PatchImage, DATA_VA
from reconstruct import TABLE_START, TABLE_END, OBJECT_FIELDS
from call_evidence import memory_calls


def read_json(path):
    base = PROJECT_ROOT / 'recovery' if path.startswith(('evidence/', 'resources/')) else SOURCE_ROOT
    return json.loads((base / path).read_text(encoding='utf-8'))


class StaticRecoveryTests(unittest.TestCase):
    def test_import_table_bounds(self):
        image=PEImage.__new__(PEImage)
        image.base=0x400000
        image.memory=bytearray(256)
        image.directories=[(0,0),(0x40,40)]
        struct.pack_into('<IIIII',image.memory,0x40,0,0,0,0x90,0)
        name=b'KERNEL32.dll\0'
        image.memory[0x90:0x90+len(name)]=name
        self.assertEqual(image.imported_dlls(),['KERNEL32.dll'])
        image.directories[1]=(0x40,20)
        with self.assertRaises(ValueError): image.imported_dlls()
        image.directories[1]=(0x40,40)
        struct.pack_into('<I',image.memory,0x40,0xA0)
        struct.pack_into('<I',image.memory,0x4C,0)
        with self.assertRaises(ValueError): image.imported_dlls()
        image.directories[1]=(0,0)
        self.assertEqual(image.imported_dlls(),[])
        image.directories=[]
        self.assertEqual(image.imported_dlls(),[])
        image.directories=[(0,0),(0x40,40)]
        struct.pack_into('<I',image.memory,0x4C,0x90)
        image.memory[0x90:]=b'A'*(len(image.memory)-0x90)
        with self.assertRaises(ValueError): image.imported_dlls()

    def test_runtime_dependency_contract(self):
        from verify_app import check_runtime_dependencies
        check_runtime_dependencies(['KERNEL32.dll', 'USER32.dll', 'MFCORE.dll'], 'Publish')
        check_runtime_dependencies(['VCRUNTIME140.dll'], 'Release')
        check_runtime_dependencies(['VCRUNTIME140D.dll'], 'Debug')
        for dependency in ['mfc140.dll', 'MSVCP140.dll', 'VCRUNTIME140.dll',
                           'ucrtbase.dll', 'api-ms-win-crt-runtime-l1-1-0.dll']:
            with self.subTest(dependency=dependency), self.assertRaises(AssertionError):
                check_runtime_dependencies(['KERNEL32.dll', dependency], 'Publish')
        with self.assertRaises(AssertionError):
            check_runtime_dependencies(['KERNEL32.dll'], 'Release')
        for imports, configuration in [(['VCRUNTIME140D.dll'], 'Release'),
                                       (['VCRUNTIME140.dll'], 'Debug')]:
            with self.subTest(configuration=configuration), self.assertRaises(AssertionError):
                check_runtime_dependencies(imports, configuration)

    def test_core_has_no_gui_or_mfc_dependency(self):
        from verify_app import check_core_boundary, check_runtime_dependencies
        check_core_boundary()
        check_runtime_dependencies(['USER32.dll', 'VCRUNTIME140.dll'], 'Release')
        check_runtime_dependencies(['USER32.dll', 'VCRUNTIME140D.dll'], 'Debug')
        check_runtime_dependencies(['USER32.dll'], 'Publish')
        for configuration, library in [('Release', 'mfc140.dll'), ('Debug', 'mfc140d.dll'), ('Publish', 'mfc140.dll')]:
            with self.subTest(configuration=configuration), self.assertRaises(AssertionError):
                check_runtime_dependencies(['USER32.dll', library], configuration)

    @classmethod
    def setUpClass(cls):
        cls.pe = PEImage(PROJECT_ROOT / 'recovery/sample-2026/San9PKHard.exe')

    def test_city_auto_apply_caption(self):
        from dialog_customizations import control_title
        self.assertEqual(control_title(133, 1133, "自动同步配置信息"), "自动应用都市配置")
        self.assertEqual(control_title(132, 1133, "unchanged"), "unchanged")
        with self.assertRaises(AssertionError):
            control_title(133, 1133, "unexpected source")

    def test_sample_architecture(self):
        self.assertEqual(self.pe.machine, 0x14C)

    def test_initializer_machine_code_oracle(self):
        """Read original x86 instructions, independently of Hex-Rays expressions."""
        expected = bytearray(self.pe.memory)
        initializers = read_json('generated/initializers.json')
        self.assertEqual(len(initializers), 317)
        for entry in initializers:
            code = self.pe.read(entry['function_va'], 16)
            self.assertEqual(code[0], 0xA1)
            source = struct.unpack_from('<I', code, 1)[0]
            # One initializer derives its value from another initialized global.
            base = struct.unpack_from('<I', expected, source-self.pe.base)[0]
            pos, offset = 5, 0
            if code[pos] == 0x05:  # add eax, imm32
                offset = struct.unpack_from('<I', code, pos+1)[0]
                pos += 5
            elif code[pos:pos+2] == b'\x83\xC0':  # add eax, sign-extended imm8
                offset = struct.unpack_from('<b', code, pos+2)[0]
                pos += 3
            self.assertEqual(code[pos], 0xA3)  # mov [absolute], eax
            destination = struct.unpack_from('<I', code, pos+1)[0]
            self.assertEqual(code[pos+5], 0xC3)
            self.assertEqual(destination, entry['destination'])
            value = (base + offset) & 0xFFFFFFFF
            self.assertEqual(value, entry['value'])
            struct.pack_into('<I', expected, destination-self.pe.base, value)
        start = DATA_VA - self.pe.base
        seed = (SOURCE_ROOT / 'generated/companion_data.bin').read_bytes()
        self.assertEqual(seed, expected[start:start+len(seed)])

    def test_relocations_come_from_original_table(self):
        rows = read_json('generated/relocations.json')
        self.assertEqual(len(rows), (TABLE_END-TABLE_START)//4)
        self.assertEqual([r['offset'] for r in rows[:7]], OBJECT_FIELDS)
        for row in rows[7:]:
            self.assertEqual(row['va'], self.pe.integer(row['table_va']))
            self.assertEqual(PatchImage().read32(row['va']), row['initial_value'])
        self.assertEqual(len({r['va'] for r in rows[7:]}), len(rows)-7)

    def test_rebase_absolute_and_relative_operands(self):
        image = PatchImage()
        before = image.read32(0x420091)  # rel32 operand; wraps as uint32
        changes = image.rebase(0x10000000)
        self.assertEqual(len(changes), 969)
        self.assertEqual(image.object32(3700), 0x10004000)
        self.assertEqual(image.object32(7620), 0x100031B0)
        self.assertEqual(image.read32(0x420107), 0x100000D0)  # absolute immediate
        self.assertEqual(image.read32(0x420091), (before + 0x10000000-0xA0000) & 0xFFFFFFFF)
        for row in changes:
            self.assertEqual(row['after'], (row['before']+0x10000000-0xA0000)&0xFFFFFFFF)

    def test_only_declared_dwords_change(self):
        image = PatchImage()
        original = bytes(image.data)
        image.rebase(0x20000000)
        allowed = set(range(0x420050-DATA_VA, 0x420054-DATA_VA))
        for row in image.relocations:
            if row['kind'] == 'image_dword':
                allowed.update(range(row['va']-DATA_VA, row['va']-DATA_VA+4))
        actual = {i for i,(a,b) in enumerate(zip(original,image.data)) if a!=b}
        self.assertTrue(actual <= allowed)

    def test_rebase_repeat_inverse_and_negative_delta(self):
        image = PatchImage()
        original = bytes(image.data)
        image.rebase(0x70000000)
        self.assertEqual(image.rebase(0x70000000), [])
        image.rebase(0x10000000)
        self.assertEqual(image.object32(3700), 0x10004000)
        image.rebase(0xA0000)
        self.assertEqual(bytes(image.data), original)

    def test_invalid_bases_leave_image_unchanged(self):
        image = PatchImage()
        original = bytes(image.data)
        for base in (0, -1, 0x10000001, 0xFFFFF000, 0x100000000):
            with self.assertRaises(ValueError):
                image.rebase(base)
            self.assertEqual(bytes(image.data), original)

    def test_resources_preserve_original_bytes(self):
        rows = read_json('resources/index.json')
        self.assertEqual(len(rows), 11)
        for row in rows:
            raw = (PROJECT_ROOT / 'recovery/resources' / row['file']).read_bytes()
            self.assertEqual(raw, self.pe.read(row['va'], row['size']))
        dialogs = read_json('resources/dialogs.json')
        self.assertEqual(len(dialogs), 6)
        self.assertEqual(sum(len(x['dialog']['controls']) for x in dialogs), 282)
        for row in dialogs:
            self.assertLessEqual(row['dialog']['parsed_size'], row['resource']['size'])

    def test_catalog_has_no_silent_omissions(self):
        calls = memory_calls()
        catalog = read_json('generated/write_catalog.json')
        writes = [c for c in calls if c['api']=='WriteProcessMemory']
        self.assertEqual(len(writes), 1525)
        self.assertEqual([(x['function_va'],x['instruction_va']) for x in catalog],
                         [(x['function_va'],x['instruction_va']) for x in writes])
        self.assertEqual(sum(x['status']=='static_bytes' for x in catalog), 1087)
        self.assertEqual(sum(x['status']=='dynamic_expression' for x in catalog), 438)
        image = PatchImage()
        for row in catalog:
            if row['status']=='static_bytes':
                payload = bytes.fromhex(row['bytes_hex'])
                self.assertEqual(len(payload), row['size'])
                # All currently resolved byte buffers lie in the recovered data segment.
                self.assertEqual(payload, image.read(row['source_va'], row['size']))

    def test_complete_undo_call_evidence(self):
        historical={c['instruction_va'] for c in read_json('evidence/memory_calls.json')
                    if c['api']=='WriteProcessMemory' and c['function_va']==0x414E40}
        evidence=read_json('evidence/runtime/undo_calls.json')
        calls=evidence['calls'];current={r['instruction_va'] for r in calls}
        self.assertEqual(len(historical),397)
        self.assertEqual(len(calls),len(current))
        self.assertEqual(len(current),542)
        self.assertLessEqual(historical,current)
        self.assertEqual(len(current-historical),145)
        self.assertEqual(min(current-historical),0x417703)
        self.assertEqual(self.pe.read(0x414E83,6),bytes.fromhex('8b 3d 40 c0 41 00'))
        for row in calls:
            self.assertEqual(row['function_va'],0x414E40)
            self.assertEqual(row['api'],'WriteProcessMemory')
            self.assertEqual(len(row['args']),5)
            self.assertLess(row['instruction_va'],0x41865E) # EDI repurposed only afterwards.
            self.assertEqual(self.pe.read(row['instruction_va'],2),bytes.fromhex(row['instruction_bytes']))
            self.assertEqual(row['instruction_bytes'],'ffd7')
        text=(PROJECT_ROOT / 'recovery/evidence/runtime/sub_414E40.c').read_text(encoding='utf-8')
        self.assertNotIn('JUMPOUT',text)
        self.assertEqual(text.count('WriteProcessMemory('),len(calls))
        rows=[r for r in read_json('generated/write_catalog.json') if r['operation']=='restore']
        self.assertEqual({r['instruction_va'] for r in rows},current)
        self.assertTrue(all(r['evidence_source']=='evidence/runtime/undo_calls.json' for r in rows))

    def test_native_resource_container_preserves_payloads(self):
        raw = (PROJECT_ROOT / 'recovery/resources/RecoveredResources.res').read_bytes()
        expected = {tuple(r['keys']): (PROJECT_ROOT / 'recovery/resources'/r['file']).read_bytes()
                    for r in read_json('resources/index.json')}
        actual, pos = {}, 0
        while pos < len(raw):
            size, header_size = struct.unpack_from('<II',raw,pos)
            type_tag, kind, name_tag, name = struct.unpack_from('<4H',raw,pos+8)
            self.assertEqual((type_tag,name_tag),(0xFFFF,0xFFFF))
            self.assertEqual(header_size,32)
            language = struct.unpack_from('<H',raw,pos+22)[0]
            payload = raw[pos+header_size:pos+header_size+size]
            self.assertEqual(len(payload),size)
            if size:
                actual[(kind,name,language)] = payload
            pos += header_size + ((size+3)&~3)
        self.assertEqual(pos,len(raw))
        self.assertEqual(actual,expected)

    def test_native_arrays_match_byte_authority(self):
        text = (SOURCE_ROOT / 'generated/PatchCatalog.h').read_text(encoding='ascii')
        arrays = {}
        for m in re.finditer(r'bytes_([0-9A-F]+)_([0-9A-F]+)\[\] = \{(.*?)\};', text, re.S):
            raw = bytes(int(x,16) for x in re.findall(r'0x([0-9A-F]{2})',m[3]))
            arrays[(int(m[1],16),int(m[2],16))] = raw
        rows = [r for r in read_json('generated/write_catalog.json') if r['status']=='static_bytes']
        self.assertEqual(set(arrays), {(r['source_va'],r['size']) for r in rows})
        for row in rows:
            self.assertEqual(arrays[(row['source_va'],row['size'])], bytes.fromhex(row['bytes_hex']))

    def test_function_evidence_and_raw_disassembly(self):
        rows = read_json('evidence/functions.json')
        self.assertEqual(len(rows), 929)
        self.assertEqual(read_json('evidence/ida_export.json')['unowned_recognized_code'], [])
        self.assertTrue(any(r['va']==0x414E40 and 'pseudocode' in r for r in rows))
        errors = [r for r in rows if 'decompile_error' in r]
        self.assertEqual([r['va'] for r in errors], [0x41A60C])
        pattern = re.compile(r'^([0-9A-F]{8})  ([0-9a-f]{2}(?: [0-9a-f]{2})*)\s')
        for row in rows:
            for line in (PROJECT_ROOT / 'recovery/evidence'/row['assembly']).read_text(encoding='utf-8').splitlines():
                m = pattern.match(line)
                if m:
                    raw = bytes.fromhex(m[2])
                    self.assertEqual(raw, self.pe.read(int(m[1],16),len(raw)))



if __name__ == '__main__':
    unittest.main()
