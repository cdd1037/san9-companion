"""Metadata is checked against independent read/save/transfer/DDX evidence."""
from pathlib import Path
import re
import sys
import unittest

PROJECT_ROOT = Path(__file__).resolve().parents[1]
SOURCE_ROOT = PROJECT_ROOT / 'src'
sys.path.insert(0, str(PROJECT_ROOT / 'tools'))
from recover_parameters import recover, outputs
from pe_image import PEImage


class ParameterEvidenceTests(unittest.TestCase):
    def test_zone_city_default_disabled(self):
        field = next(f for f in recover()['fields'] if f['control_id'] == 1061)
        self.assertEqual(field['default'], 0)
        lines = (SOURCE_ROOT / '../assets/config/San9PKHardPara.txt').read_text().splitlines()
        self.assertEqual(int(lines[field['line'] - 1]) & field['mask'], 0)

    def test_default_machine_code(self):
        image = PEImage(PROJECT_ROOT / 'recovery/sample-2026/San9PKHard.exe')
        registers, stores = {}, {}
        listing = (PROJECT_ROOT / 'recovery/evidence/disassembly/00409430.asm').read_text(encoding='utf-8')
        for text in listing.splitlines():
            match = re.match(r'^([0-9A-F]{8})  ((?:[0-9a-f]{2} )+)\s+(.*)', text)
            self.assertIsNotNone(match)
            va, raw, instruction = match.groups()
            raw = bytes.fromhex(raw)
            self.assertEqual(image.read(int(va, 16), len(raw)), raw)
            if len(raw) == 5 and 0xb8 <= raw[0] <= 0xbf:
                registers[raw[0] - 0xb8] = int.from_bytes(raw[1:], 'little')
            elif len(raw) == 2 and raw[0] in (0x31, 0x33) and raw[1] >= 0xc0:
                dest, src = (raw[1] >> 3) & 7, raw[1] & 7
                if dest == src:
                    registers[dest] = 0
            elif len(raw) in (6, 10) and raw[0] in (0x89, 0xc7) and raw[1] & 0xc7 == 0x86:
                offset = int.from_bytes(raw[2:6], 'little')
                if offset in range(148, 500, 4):
                    if raw[0] == 0xc7:
                        self.assertEqual(raw[1], 0x86)
                        value = int.from_bytes(raw[6:], 'little')
                    else:
                        self.assertIn((raw[1] >> 3) & 7, registers)
                        value = registers[(raw[1] >> 3) & 7]
                    stores[offset] = value
            else:
                written = re.match(r'(?:mov|lea|add|sub|inc|dec|and|or|xor)\s+(eax|ecx|edx|ebx|esp|ebp|esi|edi)\b', instruction)
                if written:
                    registers.pop(('eax','ecx','edx','ebx','esp','ebp','esi','edi').index(written[1]), None)
                if instruction.startswith('call'):
                    for reg in (0, 1, 2):
                        registers.pop(reg, None)
        self.assertEqual(stores, {r['host_offset']: r['default'] for r in recover()['fields']})

    def test_generated_metadata_current(self):
        for name, expected in outputs(recover()).items():
            self.assertEqual((SOURCE_ROOT / 'generated' / name).read_text(encoding='utf-8'), expected)

    def test_load_assembly(self):
        """Symbolically trace the saved x86 listing from atoi to object stores.

        This is not a CPU emulator: only MOV/SHR/AND on the atoi-derived values
        are accepted. Verify listing bytes against the pinned PE as well.
        """
        image = PEImage(PROJECT_ROOT / 'recovery/sample-2026/San9PKHard.exe')
        regs, stores, line = {}, [], 0
        assembly = (PROJECT_ROOT / 'recovery/evidence/disassembly/004191C0.asm').read_text(encoding='utf-8')
        for text in assembly.splitlines():
            match = re.match(r'^([0-9A-F]{8})  ((?:[0-9a-f]{2} )+)\s+(.*)', text)
            self.assertIsNotNone(match)
            va, raw, instruction = match.groups()
            raw = bytes.fromhex(raw)
            self.assertEqual(image.read(int(va, 16), len(raw)), raw)
            if 'aSan9pkhardpers' in instruction:
                break
            instruction = instruction.split(';')[0].strip()
            if instruction == 'call    ebx':
                line += 1
                regs = {'eax': (line, 0, 0xffffffff)}
                continue
            mov = re.fullmatch(r'mov\s+(eax|ecx|edx), (.*)', instruction)
            if mov:
                dest, src = mov.groups()
                if src in regs:
                    regs[dest] = regs[src]
                else:
                    regs.pop(dest, None)
            op = re.fullmatch(r'(shr|and)\s+(eax|ecx|edx), ([0-9A-Fa-f]+h?|0)', instruction)
            if op and op[2] in regs:
                current_line, shift, mask = regs[op[2]]
                value = int(op[3][:-1], 16) if op[3].endswith('h') else int(op[3])
                regs[op[2]] = (current_line, shift + value, mask >> value) if op[1] == 'shr' else (current_line, shift, mask & value)
            store = re.fullmatch(r'mov\s+\[esi\+([0-9A-Fa-f]+)h\], (eax|ecx|edx)', instruction)
            if store:
                self.assertIn(store[2], regs)
                n, shift, mask = regs[store[2]]
                self.assertIn(mask, (1, 0xffffffff))
                stores.append((int(store[1], 16), n, (1 << shift) if mask == 1 else 0))
        expected = [(r['host_offset'], r['line'], r['mask']) for r in recover()['fields']]
        self.assertEqual(line, 34)
        self.assertEqual(sorted(stores), sorted(expected))


if __name__ == '__main__':
    unittest.main()
