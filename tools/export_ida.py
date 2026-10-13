"""Run in IDA's Python console/MCP. Reads the loaded sample; exports into this project.

No debugger, process attachment, patch_bytes, or save_database operations are used.
Analysis repairs define UndoModify and handlers referenced by MFC message maps.
"""
from pathlib import Path
import json

import ida_auto
import ida_bytes
import ida_funcs
import ida_hexrays as hx
import ida_lines
import ida_name
import ida_nalt
import ida_segment
import idautils

from project_paths import PROJECT_ROOT, SOURCE_ROOT
SAMPLE = PROJECT_ROOT / "recovery/sample-2026" / "San9PKHard.exe"
OUT = PROJECT_ROOT / "recovery/evidence"


def save(name, value):
    (OUT / name).write_text(json.dumps(value, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")


def expression(e, cf, depth=0):
    result = {"op": hx.get_ctype_name(e.op), "text": ida_lines.tag_remove(e.print1(cf))}
    if depth > 24:
        result["truncated"] = True
        return result
    if e.op == hx.cot_num:
        result["value"] = e.numval()
    elif e.op == hx.cot_obj:
        result.update(va=e.obj_ea, size=e.type.get_size(), array=e.type.is_array())
    elif e.op == hx.cot_var:
        result["index"] = e.v.idx
    elif e.op == hx.cot_call:
        result["target"] = expression(e.x, cf, depth + 1)
        result["args"] = [expression(a, cf, depth + 1) for a in e.a]
    elif e.op in (hx.cot_cast, hx.cot_ref, hx.cot_ptr, hx.cot_neg, hx.cot_bnot,
                  hx.cot_lnot, hx.cot_preinc, hx.cot_predec, hx.cot_postinc, hx.cot_postdec):
        result["x"] = expression(e.x, cf, depth + 1)
        result["size"] = e.type.get_size()
    elif e.op in (hx.cot_memptr, hx.cot_memref):
        result.update(x=expression(e.x, cf, depth + 1), member=e.m)
    elif e.op == hx.cot_tern:
        for key in ("x", "y", "z"):
            result[key] = expression(getattr(e, key), cf, depth + 1)
    elif hx.cot_asg <= e.op <= hx.cot_fdiv or e.op == hx.cot_idx:
        result["x"] = expression(e.x, cf, depth + 1)
        result["y"] = expression(e.y, cf, depth + 1)
    if e.op in (hx.cot_add, hx.cot_sub, hx.cot_idx) and e.x.type.is_ptr():
        result["stride"] = e.x.type.get_pointed_object().get_size()
    return result


def main():
    if Path(ida_nalt.get_input_file_path()).resolve() != SAMPLE.resolve():
        raise RuntimeError("Wrong IDA input; expected the workspace 2026 sample")
    (OUT / "decompiled").mkdir(parents=True, exist_ok=True)
    (OUT / "disassembly").mkdir(exist_ok=True)
    repairs = [
        (0x414E40, 0x418700, None),
        (0x4016A0, 0x4016EE, 0x41C378), (0x402310, 0x40235E, 0x41C5A8),
        (0x402610, 0x402642, 0x41C5D8), (0x402C10, 0x402C5E, 0x41C700),
        (0x4042C0, 0x404444, 0x41C858), (0x4057A0, 0x40581C, 0x41C9F8),
        (0x405C10, 0x405C21, 0x41CA28), (0x405C70, 0x405C92, 0x41CAA0),
        (0x405CA0, 0x405CC2, 0x41CAB8), (0x409DF0, 0x409E10, 0x41CF20),
    ]
    for start, end, message_entry in repairs:
        if message_entry is not None and ida_bytes.get_dword(message_entry + 20) != start:
            raise RuntimeError(f'MFC entry does not reference {start:X}')
        if ida_funcs.get_func(start) is None and not ida_funcs.add_func(start, end):
            raise RuntimeError(f'Could not define function at {start:X}')
    ida_auto.auto_wait()
    if not hx.init_hexrays_plugin():
        raise RuntimeError("Hex-Rays unavailable")

    imports = []
    for i in range(ida_nalt.get_import_module_qty()):
        module = ida_nalt.get_import_module_name(i)
        def cb(ea, name, ordinal):
            imports.append(dict(va=ea, module=module, name=name, ordinal=ordinal))
            return True
        ida_nalt.enum_import_names(i, cb)
    save("imports.json", imports)
    api_by_va = {r["va"]: r["name"] for r in imports}
    names = {ea: name for ea, name in idautils.Names()}
    save("symbols.json", [{"va": ea, "name": name} for ea, name in sorted(names.items())])
    functions, calls, assignments = [], [], []

    class Visitor(hx.ctree_visitor_t):
        def __init__(self, cf):
            super().__init__(hx.CV_FAST)
            self.cf = cf

        def visit_expr(self, e):
            if e.op == hx.cot_call and e.x.op == hx.cot_obj:
                target = api_by_va.get(e.x.obj_ea, "") or ""
                if any(s in target for s in ("ProcessMemory", "VirtualAllocEx", "VirtualProtectEx")):
                    calls.append(dict(function_va=self.cf.entry_ea, instruction_va=e.ea,
                                      api=target, args=[expression(a, self.cf) for a in e.a]))
            if e.op == hx.cot_asg and e.x.op == hx.cot_obj:
                assignments.append(dict(function_va=self.cf.entry_ea, instruction_va=e.ea,
                                        destination=e.x.obj_ea, size=e.x.type.get_size(),
                                        value=expression(e.y, self.cf)))
            return 0

    for ea in idautils.Functions():
        f = ida_funcs.get_func(ea)
        row = dict(va=ea, name=ida_funcs.get_func_name(ea), size=f.size(),
                   chunks=list(idautils.Chunks(ea)), flags=f.flags)
        lines = []
        for start, end in row["chunks"]:
            for head in idautils.Heads(start, end):
                raw = ida_bytes.get_bytes(head, ida_bytes.get_item_size(head)) or b""
                asm = ida_lines.tag_remove(ida_lines.generate_disasm_line(head, 0) or "")
                lines.append(f"{head:08X}  {raw.hex(' '):<44}  {asm}")
        asmfile = f"disassembly/{ea:08X}.asm"
        (OUT / asmfile).write_text("\n".join(lines) + "\n", encoding="utf-8")
        row["assembly"] = asmfile
        try:
            cf = hx.decompile(ea)
            if cf is None:
                raise RuntimeError("decompile returned None")
            filename = f"decompiled/sub_{ea:X}.c"
            (OUT / filename).write_text(
                "// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.\n"
                f"// Sample VA: 0x{ea:08X}; original name: {row['name']}\n" + str(cf), encoding="utf-8")
            row["pseudocode"] = filename
            Visitor(cf).apply_to(cf.body, None)
        except Exception as ex:
            row["decompile_error"] = str(ex)
        functions.append(row)

    # Include unassigned code too; otherwise analysis gaps would silently disappear.
    with (OUT / "text_listing.asm").open("w", encoding="utf-8") as out:
        for ea in idautils.Heads(0x401000, 0x41C000):
            raw = ida_bytes.get_bytes(ea, ida_bytes.get_item_size(ea)) or b""
            out.write(f"{ea:08X}  {raw.hex(' '):<44}  " +
                      ida_lines.tag_remove(ida_lines.generate_disasm_line(ea, 0) or "") + "\n")
    save("functions.json", functions)
    save("memory_calls.json", calls)
    save("global_assignments.json", assignments)
    unowned = [ea for ea in idautils.Heads(0x401000, 0x41C000)
               if ida_bytes.is_code(ida_bytes.get_full_flags(ea)) and ida_funcs.get_func(ea) is None]
    save("ida_export.json", dict(image_base=ida_nalt.get_imagebase(), functions=len(functions), memory_calls=len(calls),
         decompile_errors=[r for r in functions if "decompile_error" in r],
         analysis_repairs=[dict(va=start, end=end, mfc_entry=entry,
                               reason="UndoModify direct call" if entry is None else "MFC message-map handler")
                           for start,end,entry in repairs],
         unowned_recognized_code=unowned,
         database_saved=False))
    print(f"Exported {len(functions)} functions, {len(calls)} memory API calls to {OUT}")


if __name__ == "__main__":
    main()
