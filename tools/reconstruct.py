"""Rebuild static artifacts from the pinned EXE and saved IDA evidence, without IDA."""
from pathlib import Path
import json
import re
import struct
import sys
from call_evidence import memory_calls
from dialog_customizations import control_title, customize_control_layout, dialog_title

from pe_image import PEImage, dialog_template
from res_file import build_resources

from project_paths import PROJECT_ROOT, SOURCE_ROOT
TABLE_START, TABLE_END = 0x42DDF8, 0x42ED1C
BASE_SLOT, DATA_START, DATA_END = 0x420050, 0x41F000, 0x430000
OBJECT_FIELDS = [7620, 3700, 4720, 4724, 4828, 4832, 5212]
OBJECT_DEFAULTS = [0xA31B0, 0xA4000, 0xA5662, 0xA5630, 0xA6E00, 0xA3CC0, 0xA1AE0]


def load(name):
    return json.loads((PROJECT_ROOT / 'recovery/evidence' / name).read_text(encoding='utf-8'))


def save(path, value):
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(value, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')


class Unresolved(ValueError):
    pass


def evaluate(e, image, address=False):
    """Evaluate only closed constant/global expressions. Never guess locals/branches."""
    op = e['op']
    if op == 'cast':
        return evaluate(e['x'], image, address)
    if op == 'num':
        return e['value'] & 0xFFFFFFFF
    if op == 'obj':
        if address or e.get('array'):
            return e['va']
        return image.integer(e['va'], e['size'])
    if op == 'ref':
        return evaluate(e['x'], image, True)
    if op in ('add', 'sub', 'mul', 'band', 'bor', 'bxor', 'shl', 'ushr'):
        x, y = evaluate(e['x'], image), evaluate(e['y'], image)
        if op in ('add', 'sub'):
            y *= e.get('stride', 1)
        return {'add': lambda: x+y, 'sub': lambda: x-y, 'mul': lambda: x*y,
                'band': lambda: x&y, 'bor': lambda: x|y, 'bxor': lambda: x^y,
                'shl': lambda: x<<y, 'ushr': lambda: x>>y}[op]() & 0xFFFFFFFF
    if op == 'idx':
        va = evaluate(e['x'], image, True) + evaluate(e['y'], image)*e.get('stride', 4)
        return va if address else image.integer(va, e.get('stride', 4))
    if op == 'ptr':
        va = evaluate(e['x'], image)
        return va if address else image.integer(va, e['size'])
    raise Unresolved(e['text'])


def initialize(image):
    result = []
    # These short routines form the compiler-generated static initializers between
    # the application code and CSan9PKHardDlg's constructor. Each has one store.
    # Expressions depend on the old injection base (one uses a preceding global).
    # The tests also reconstruct every assignment independently from x86 opcodes.
    for row in load('global_assignments.json'):
        if not 0x405EE0 <= row['function_va'] <= 0x408660:
            continue
        if row['size'] != 4 or not DATA_START <= row['destination'] <= DATA_END - 4:
            raise ValueError('Unexpected static initializer')
        value = evaluate(row['value'], image)
        image.put32(row['destination'], value)
        result.append(dict(function_va=row['function_va'], instruction_va=row['instruction_va'],
                           destination=row['destination'], value=value,
                           expression=row['value']['text']))
    return result


def old_arrays():
    source = (PROJECT_ROOT / 'recovery/reference-2019' / 'InsertAsm.h').read_text(encoding='cp936')
    source = re.sub(r'/\*.*?\*/|//[^\n]*', '', source, flags=re.S)
    result = []
    for match in re.finditer(r'\bBYTE\s+(\w+)\s*\[\s*\]\s*=\s*\{([^{}]*)\}', source):
        tokens = [x.strip() for x in match[2].split(',') if x.strip()]
        try:
            raw = bytes(int(x, 0) for x in tokens)
        except ValueError:
            continue
        if len(raw) >= 8:
            result.append((match[1], raw))
    return result


def main():
    image = PEImage(PROJECT_ROOT / 'recovery/sample-2026' / 'San9PKHard.exe')
    generated = SOURCE_ROOT / 'generated'
    generated.mkdir(exist_ok=True)
    initializers = initialize(image)
    save(generated / 'initializers.json', initializers)
    relocs = []
    for i, slot in enumerate(range(TABLE_START, TABLE_END, 4)):
        if i < len(OBJECT_FIELDS):
            row = dict(index=i, table_va=slot, kind='object_field', offset=OBJECT_FIELDS[i],
                       initial_value=OBJECT_DEFAULTS[i])
        else:
            target = image.integer(slot)
            if not DATA_START <= target <= DATA_END - 4:
                raise ValueError(f'Relocation outside data: {target:X}')
            row = dict(index=i, table_va=slot, kind='image_dword', va=target,
                       initial_value=image.integer(target))
        relocs.append(row)
    save(generated / 'relocations.json', relocs)
    seed = image.read(DATA_START, DATA_END - DATA_START)
    (generated / 'companion_data.bin').write_bytes(seed)

    # Every callsite is retained. A closed expression only resolves a possible
    # write's address and bytes; it does not prove that its branch executes.
    catalog = []
    old = old_arrays()
    for call in memory_calls():
        if call['api'] != 'WriteProcessMemory':
            continue
        args = call['args']
        row = dict(function_va=call['function_va'], instruction_va=call['instruction_va'],
                   operation='restore' if call['function_va'] == 0x414E40 else 'write',
                   evidence_source=call['evidence_source'],
                   target_expression=args[1]['text'], source_expression=args[2]['text'],
                   size_expression=args[3]['text'], status='dynamic_expression')
        try:
            target, source, size = [evaluate(args[i], image) for i in (1,2,3)]
            if not 0 < size <= 0x100000:
                raise Unresolved('Invalid/unbounded write size')
            payload = image.read(source, size)
            row.update(status='static_bytes', target_va=target, source_va=source, size=size,
                       bytes_hex=payload.hex())
            row['old_exact_byte_names'] = [name for name, data in old if data == payload]
            row['payload_relocations'] = [r['va'] - source for r in relocs
                                         if r['kind'] == 'image_dword' and source <= r['va'] < source + size]
        except (ValueError, KeyError) as ex:
            row['unresolved_reason'] = str(ex)
        catalog.append(row)
    save(generated / 'write_catalog.json', catalog)

    # Recover the byte-array representation used by the 2019 author. Names carry
    # source VA and length, never a guessed feature identity. Old equal-byte names
    # remain evidence in JSON, not authoritative symbol renames.
    header = ['#pragma once', '#include <cstdint>', '#include <cstddef>',
              'namespace san9::recovered {',
              '// Baseline static byte candidates, NOT an ordered/executable patch plan.',
              'struct StaticWrite { std::uint32_t callVA, functionVA, targetVA, sourceVA; '
              'std::size_t size; const std::uint8_t* bytes; };']
    buffers = {}
    for row in catalog:
        if row['status'] != 'static_bytes':
            continue
        key = (row['source_va'], row['size'])
        if key in buffers:
            continue
        name = f'bytes_{key[0]:08X}_{key[1]:X}'
        buffers[key] = name
        raw = bytes.fromhex(row['bytes_hex'])
        header += [f'inline constexpr std::uint8_t {name}[] = {{']
        header += ['    ' + ', '.join(f'0x{x:02X}' for x in raw[i:i+16]) + ','
                   for i in range(0,len(raw),16)]
        header += ['};']
    header += ['inline constexpr StaticWrite StaticWrites[] = {']
    for row in catalog:
        if row['status'] == 'static_bytes':
            header += ['    {' + ', '.join(f'0x{row[k]:08X}' for k in
                        ('instruction_va','function_va','target_va','source_va')) +
                        f', {row["size"]}, {buffers[(row["source_va"],row["size"])]}' + '},']
    header += ['};', '} // namespace san9::recovered']
    (generated / 'PatchCatalog.h').write_text('\n'.join(header) + '\n', encoding='ascii')

    if '--catalog-only' in sys.argv:
        manifest=json.loads((generated/'manifest.json').read_text(encoding='utf-8'))
        manifest.update(memory_api_calls=len(memory_calls()),write_calls=len(catalog),
            static_byte_calls=sum(r['status']=='static_bytes' for r in catalog),
            dynamic_calls=sum(r['status']!='static_bytes' for r in catalog))
        save(generated/'manifest.json',manifest)
        print(f'Generated {len(catalog)} write callsites; resource/parameter generation skipped.')
        return

    resource_rows, dialogs = [], []
    resource_dir = PROJECT_ROOT / 'recovery/resources'
    resource_dir.mkdir(exist_ok=True)
    for i, item in enumerate(image.resources()):
        filename = '_'.join(str(k) for k in item['keys']) + '.bin'
        if not re.fullmatch(r'[\w.-]+', filename):
            filename = f'resource_{i}.bin'
        (resource_dir / filename).write_bytes(item['data'])
        row = {k:v for k,v in item.items() if k != 'data'}
        row.update(file=filename)
        resource_rows.append(row)
        if item['keys'][0] == 5:
            dialogs.append(dict(resource=row, dialog=dialog_template(item['data'])))
    save(resource_dir / 'index.json', resource_rows)
    save(resource_dir / 'dialogs.json', dialogs)

    def quoted(value):
        if isinstance(value, dict):
            return str(value['ordinal'])
        return '"' + value.replace('\\','\\\\').replace('"','""').replace('\r','\\r').replace('\n','\\n') + '"'
    classes = {0x80:'Button',0x81:'Edit',0x82:'Static',0x83:'ListBox',0x84:'ScrollBar',0x85:'ComboBox'}
    editable = ['// Editable reconstruction; raw .bin templates remain the byte authority.',
                '#pragma code_page(65001)']
    for row in dialogs:
        _, ident, lang = row['resource']['keys']
        d = row['dialog']
        editable += [f'LANGUAGE {lang & 0x3ff}, {lang >> 10}',
                     f'{ident} DIALOGEX ' + ', '.join(map(str,d['rect'])),
                     f'STYLE 0x{d["style"]:08X}', f'EXSTYLE 0x{d["exstyle"]:08X}',
                     'CAPTION ' + quoted(dialog_title(row['resource']['keys'][1], d['title']))]
        if d['menu']: editable += ['MENU ' + quoted(d['menu'])]
        if d['window_class']: editable += ['CLASS ' + quoted(d['window_class'])]
        if 'font' in d:
            f=d['font']
            editable += [f'FONT {f["point_size"]}, {quoted(f["face"])}, '
                         f'{f.get("weight",400)}, {f.get("italic",0)}, {f.get("charset",1)}']
        editable += ['BEGIN']
        for c in d['controls']:
            c = dict(c)
            customize_control_layout(row['resource']['keys'][1], c)
            if c['creation_data']:
                raise ValueError('Editable RC generator does not support extra creation data')
            cls = c['window_class']
            if isinstance(cls,dict): cls=classes.get(cls['ordinal'],cls)
            ident = -1 if c['id'] in (0xFFFF,0xFFFFFFFF) else c['id']
            # CONTROL implicitly adds WS_VISIBLE, even with a numeric style.
            style = f'0x{c["style"]:08X}'
            if not c['style'] & 0x10000000:
                style += ' | NOT 0x10000000'
            editable += [f'    CONTROL {quoted(control_title(row["resource"]["keys"][1], c["id"], c["title"]))}, {ident}, {quoted(cls)}, '
                         + style + ', ' + ', '.join(map(str,c['rect'])) +
                         f', 0x{c["exstyle"]:08X}, {c["help_id"]}']
        editable += ['END', '']
    (PROJECT_ROOT / 'assets/ui/dialogs.rc').write_text('\n'.join(editable)+'\n',encoding='utf-8')

    # RC parses built-in numeric types as source/icon formats rather than raw PE
    # payloads. A native .res container preserves those payloads without conversion.
    (resource_dir / 'RecoveredResources.res').write_bytes(build_resources(resource_rows, resource_dir))

    # Portable C++ data; no Windows import and no injected-code execution.
    def byte_lines(raw):
        return '\n'.join('    ' + ', '.join(f'0x{x:02X}' for x in raw[i:i+16]) + ','
                         for i in range(0,len(raw),16))
    (generated / 'companion_data.inc').write_text(byte_lines(seed) + '\n', encoding='ascii')
    cpp_relocs = ['    {' + (f'true, {r["offset"]}' if r['kind']=='object_field'
                             else f'false, 0x{r["va"]:08X}') + '},' for r in relocs]
    (generated / 'relocations.inc').write_text('\n'.join(cpp_relocs) + '\n', encoding='ascii')

    functions = load('functions.json')
    known_functions = {row['va'] for row in functions}
    message_entries = []
    for va in range(0x41C370, 0x41F000 - 24, 4):
        message, code, first_id, last_id, signature, handler = struct.unpack('<6I',image.read(va,24))
        if handler in known_functions and 0 < message <= 0x400 and 0 < signature < 100 and first_id <= last_id <= 0xFFFF:
            message_entries.append(dict(va=va, message=message, code=code, first_id=first_id,
                                        last_id=last_id, signature=signature, handler_va=handler))
    save(generated/'mfc_message_entries.json',message_entries)
    summary = dict(sample=dict(path='../recovery/sample-2026/San9PKHard.exe',
                              size=len(image.raw), image_base=image.base, entry_va=image.entry,
                              coff_timestamp=image.timestamp, sections=image.sections),
                   architecture='x86 / PE32 / MFC42 / ANSI', functions=len(functions),
                   decompiled=sum('pseudocode' in x for x in functions),
                   memory_api_calls=len(memory_calls()), write_calls=len(catalog),
                   static_byte_calls=sum(r['status']=='static_bytes' for r in catalog),
                   dynamic_calls=sum(r['status']!='static_bytes' for r in catalog),
                   static_initializers=len(initializers), relocation_entries=len(relocs),
                   relocation_object_fields=len(OBJECT_FIELDS),
                   allocation_size=0xB000, original_injection_base=0xA0000,
                   resources=len(resource_rows), dialogs=len(dialogs),
                   source_is_original_author_source=False, live_validation=False,
                   executable_replacement=False)
    save(generated / 'manifest.json', summary)
    from recover_parameters import recover, outputs
    for name, content in outputs(recover()).items():
        (generated / name).write_text(content, encoding='utf-8')
    print(json.dumps({k:v for k,v in summary.items() if k != 'sample'},ensure_ascii=False,indent=2))


if __name__ == '__main__':
    main()
