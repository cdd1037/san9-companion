"""Read-only export of complete undo call evidence. No IDB edits/saves or patches."""
from pathlib import Path
import json
import ida_bytes
import ida_hexrays as hx
from export_ida import expression
from pe_image import PEImage
from project_paths import PROJECT_ROOT, SOURCE_ROOT
START,END=0x414E40,0x4186F1

def export():
    image=PEImage(PROJECT_ROOT/'recovery/sample-2026/San9PKHard.exe')
    # The open database may use the original input path. Compare actual bytes,
    # including file-backed globals; IDA represents uninitialized BSS as unknown.
    for start,end in [(START,END),(0x41F000,0x42F000)]:
        if ida_bytes.get_bytes(start,end-start)!=image.read(start,end-start):
            raise ValueError('Open IDB bytes differ from the workspace sample')
    cf=hx.decompile(START)
    if cf is None or 'JUMPOUT' in str(cf): raise ValueError('Incomplete undo decompilation')
    calls=[]
    class Visitor(hx.ctree_visitor_t):
        def __init__(self): super().__init__(hx.CV_FAST)
        def visit_expr(self,e):
            if e.op==hx.cot_call and e.x.op==hx.cot_obj and e.x.obj_ea==0x41C040:
                raw=ida_bytes.get_bytes(e.ea,2)
                if raw!=b'\xff\xd7': raise ValueError(f'Unexpected undo call at {e.ea:X}')
                calls.append(dict(function_va=START,instruction_va=e.ea,api='WriteProcessMemory',
                    args=[expression(a,cf) for a in e.a],instruction_bytes=raw.hex()))
            return 0
    Visitor().apply_to(cf.body,None)
    calls.sort(key=lambda row:row['instruction_va'])
    if len(calls)!=542 or len({r['instruction_va'] for r in calls})!=542: raise ValueError('Unexpected undo call count')
    result=dict(source='Read-only Hex-Rays ctree export; undo and data bytes compared with workspace PE',
        function_va=START,function_end=END,api_iat=0x41C040,calls=calls)
    (PROJECT_ROOT / 'recovery/evidence/runtime/undo_calls.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    print('Exported 542 undo calls; no binary or IDB modification.')
if __name__=='__main__': export()
