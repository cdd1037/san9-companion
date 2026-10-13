"""Generate fixed injection data from the separately repaired 2026 evidence.

The state record is NOT a CWnd: modern MFC objects never occupy recovered offsets.
No original host instructions are executed and no old injector is linked.
"""
from pathlib import Path
import json
import re
from pe_image import PEImage
from runtime_layout import header as layout_header
from injection_names import header as injection_header, name_symbols, name_fields

from project_paths import PROJECT_ROOT, SOURCE_ROOT
OUT = SOURCE_ROOT / 'generated'


def scalar_array(row):
    """IDA may define an array while ctree also reads its first scalar element.

    Keep the scalar lvalue (including &name), and translate indexed uses to an
    explicit array view. Never let a scalar address operand decay to a pointer.
    """
    return (row['defined_array'] and not row['array'] and not row['string']
            and '*' not in row['type'])


def generate(output=OUT):
    output.mkdir(parents=True, exist_ok=True)
    (output / "RuntimeLayout2026.h").write_text(layout_header(), encoding="utf-8")
    (output / "InjectionNames2026.h").write_text(injection_header(), encoding="utf-8")
    objects = json.loads((PROJECT_ROOT / 'recovery/evidence/runtime/objects.json').read_text())
    image = PEImage(PROJECT_ROOT / 'recovery/sample-2026/San9PKHard.exe')
    (output / 'OfficialLoyalty.inc').write_text(','.join(str(x) for x in image.read(0x41CD60,77)),encoding='utf-8')
    macros = []
    for row in objects.values():
        va, name = row['va'], row['name']
        if not 0x41F000 <= va < 0x430000 or not name:
            continue
        typ = row['defined_type'] or row['type']
        if name.startswith('sub_'):
            expr = f'pointer<BYTE>(0x{va:X})'
        elif row['string']:
            expr = f'pointer<char>(0x{va:X})'
        elif scalar_array(row):
            expr = f'global<{row["type"]}>(0x{va:X})'
        elif row['defined_array']:
            typ = typ.split('[')[0].strip()
            expr = f'pointer<{typ}>(0x{va:X})'
        else:
            typ = typ.replace('_UNKNOWN', 'DWORD')
            expr = f'global<{typ}>(0x{va:X})'
        macros.append(f'#define {name} ({expr})')
    (output / 'Symbols.inc').write_text(name_symbols('\n'.join(macros)+'\n'), encoding='utf-8')
    ctor = (PROJECT_ROOT / 'recovery/evidence/runtime/sub_408670.c').read_text()
    constants = []
    for offset, value in re.findall(r'\*\(this \+ (\d+)\) = (.*?);', ctor):
        offset = int(offset)*4
        if offset >= 7624:
            continue
        value = re.sub(r'\(char \*\)&loc_([0-9A-F]+)', r'0x\1', value)
        if not re.fullmatch(r'[-\dA-Fa-fx +]+', value):
            raise ValueError(value)
        if offset == 6572:
            # m_dwOldOfficerBasicInt: the companion reversed the two displacements.
            # TC-101 at 0x4B2E37 is 60 8B 4E 58 (remake RE-SAN9PK-0067).
            # Undo uses captured session bytes; this corrects the legacy registration.
            if int(value, 0) != 0x604E8B58:
                raise ValueError('Officer ability old-byte registration changed in evidence')
            value = '0x584E8B60'
        constants.append(f'field<DWORD>({offset}) = static_cast<DWORD>({value});')
    (output / 'StateConstants.inc').write_text(name_fields('\n'.join(constants)+'\n'),encoding='utf-8')
    print('Generated fixed 2026 injection data; maintained C++ source is untouched.')


if __name__ == '__main__':
    generate()

