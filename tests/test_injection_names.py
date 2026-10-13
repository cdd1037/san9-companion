"""Check semantic names against independent legacy source and sample bytes."""
from pathlib import Path
import json
import re
import sys
import tempfile
import contextlib
import io
import unittest

PROJECT_ROOT = Path(__file__).resolve().parents[1]
SOURCE_ROOT = PROJECT_ROOT / 'src'
sys.path.insert(0, str(PROJECT_ROOT / 'tools'))
from injection_names import catalog, header, original_names, rename_tokens, name_fields
from pe_image import PEImage
from recover_runtime import generate


def without_comments(text):
    return re.sub(r'/\*.*?\*/|//[^\n]*', '', text, flags=re.S)


class InjectionNamesTests(unittest.TestCase):
    def test_legacy_code_names_match_complete_arrays(self):
        source = without_comments((PROJECT_ROOT / 'recovery/reference-2019/InsertAsm.h').read_text(encoding='gb18030'))
        arrays = {}
        for name, values in re.findall(r'BYTE\s+(\w+)\s*\[[^;=]*=\s*\{([^{}]*)\}', source):
            if re.sub(r'0x[\da-fA-F]+|\b\d+\b|[\s,]', '', values):
                continue
            arrays[name] = bytes(int(v, 0) for v in re.findall(r'0x[\da-fA-F]+|\b\d+\b', values))
        image = PEImage(PROJECT_ROOT / 'recovery/sample-2026/San9PKHard.exe')
        objects = json.loads((PROJECT_ROOT / 'recovery/evidence/runtime/objects.json').read_text())
        addresses = {r['name']: r['va'] for r in objects.values()}
        for old, row in catalog()['symbols'].items():
            expected = arrays[row['legacy']]
            self.assertGreaterEqual(len(expected), 6)
            self.assertEqual(image.read(addresses[old], len(expected)), expected, old)

    def test_constructor_names_match_legacy_initializer_order(self):
        source = without_comments((PROJECT_ROOT / 'recovery/reference-2019/San9PKHardDlg.cpp').read_text(encoding='gb18030'))
        legacy = [(n, int(v, 0) & 0xFFFFFFFF) for n, v in re.findall(
            r'\b(m_\w+)\((0x[0-9A-Fa-f]+|\d+)\)', source)]
        ctor = (PROJECT_ROOT / 'recovery/evidence/runtime/sub_408670.c').read_text()
        recovered = {int(o)*4: int(v, 0) & 0xFFFFFFFF for o, v in re.findall(
            r'\*\(this \+ (\d+)\) = (-?\d+|0x[0-9A-Fa-f]+);', ctor)}
        rows = {int(o): r for o, r in catalog()['fields'].items()
                if r['evidence'].startswith('sub_408670 constructor')}
        for offset, row in rows.items():
            index = next(i for i, pair in enumerate(legacy) if pair[0] == row['legacy'])
            self.assertEqual(recovered[offset], legacy[index][1], row['legacy'])
            # Every mapping must belong to at least a three-field contiguous run.
            sequences = []
            for start in range(offset-8, offset+1, 4):
                if all(o in rows for o in range(start, start+12, 4)):
                    sequences.append([rows[o]['legacy'] for o in range(start, start+12, 4)])
            self.assertTrue(any(seq == [n for n, _ in legacy[i:i+3]]
                                for seq in sequences for i in range(max(0, index-2), index+1)), row['legacy'])

    def test_names_preserve_literals_and_generated_header(self):
        self.assertEqual(rename_tokens('v5; "v5"; // v5\n/* v5 */ v50;', {'v5': 'gameProcess'}),
                         'gameProcess; "v5"; // v5\n/* v5 */ v50;')
        source = '"state + 5224"; // field<DWORD>(5224)\nstate + 5224;'
        self.assertEqual(name_fields(source),
                         '"state + 5224"; // field<DWORD>(5224)\nstate + san9::injection2026::CityAddresses;')
        self.assertEqual((SOURCE_ROOT / 'generated/InjectionNames2026.h').read_text(encoding='utf-8'), header())

    def test_data_regeneration_preserves_maintained_source(self):
        sources = {path: path.read_bytes() for path in (SOURCE_ROOT / 'runtime').glob('*.cpp')}
        with tempfile.TemporaryDirectory() as directory:
            output = Path(directory)
            with contextlib.redirect_stdout(io.StringIO()):
                generate(output)
            self.assertEqual({p.name for p in output.iterdir()},
                             {'RuntimeLayout2026.h', 'InjectionNames2026.h', 'OfficialLoyalty.inc',
                              'Symbols.inc', 'StateConstants.inc'})
            for path in output.iterdir():
                self.assertEqual(path.read_bytes(), (SOURCE_ROOT / 'generated' / path.name).read_bytes())
        for path, content in sources.items():
            self.assertEqual(path.read_bytes(), content)
        self.assertFalse((SOURCE_ROOT / 'generated/RuntimeBranches.inc').exists())


if __name__ == '__main__':
    unittest.main()
