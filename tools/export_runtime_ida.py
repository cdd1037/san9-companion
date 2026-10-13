"""Run inside the existing workspace IDA session; never patches/saves the binary.

The prior export missed the CALL at 0x417703 and treated its continuation as data.
This repairs instruction classification, then exports complete branch evidence.
"""
from pathlib import Path
import json
import ida_auto
import ida_bytes
import ida_hexrays as hx
import ida_name
import ida_nalt
import ida_typeinf
import ida_ua

from project_paths import PROJECT_ROOT, SOURCE_ROOT
def main():
    expected=PROJECT_ROOT/'recovery/sample-2026/San9PKHard.exe'
    if Path(ida_nalt.get_input_file_path()).resolve()!=expected.resolve():
        raise RuntimeError('Wrong workspace sample')
    if ida_bytes.get_bytes(0x417703,2)!=bytes.fromhex('ff d7'):
        raise RuntimeError('Unexpected undo continuation')
    ida_bytes.del_items(0x417703,0,0x417B02-0x417703)
    ea=0x417703
    while ea<0x417B02:
        size=ida_ua.create_insn(ea)
        if not size: raise RuntimeError(f'Cannot decode {ea:X}')
        ea+=size
    ida_auto.auto_wait()
    hx.mark_cfunc_dirty(0x414E40)
    output=PROJECT_ROOT / 'recovery/evidence/runtime'
    output.mkdir(exist_ok=True)
    objects={}
    class Visitor(hx.ctree_visitor_t):
        def __init__(self): super().__init__(hx.CV_FAST)
        def visit_expr(self,e):
            if e.op==hx.cot_obj:
                objects[str(e.obj_ea)]={'va':e.obj_ea,'type':str(e.type),
                    'array':e.type.is_array(),'size':e.type.get_size()}
            return 0
    for ea in [0x408670,0x409430,0x409840,0x409E10,0x414E40,0x41A1F0]:
        function=hx.decompile(ea)
        text=str(function)
        if 'JUMPOUT' in text: raise RuntimeError(f'Incomplete function {ea:X}')
        (output/f'sub_{ea:X}.c').write_text(text,encoding='utf-8')
        Visitor().apply_to(function.body,None)
    for row in objects.values():
        ea=row['va']; info=ida_typeinf.tinfo_t()
        row['name']=ida_name.get_name(ea)
        row['defined_type']=str(info) if ida_nalt.get_tinfo(info,ea) else ''
        row['item_size']=ida_bytes.get_item_size(ea)
        row['string']=ida_bytes.is_strlit(ida_bytes.get_full_flags(ea))
        row['defined_array']=info.is_array()
    (output/'objects.json').write_text(json.dumps(objects,indent=2)+'\n',encoding='utf-8')
    print('Exported complete 2026 runtime evidence; database not saved.')

if __name__=='__main__': main()
