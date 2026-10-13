"""Canonical memory-call evidence: replace the incomplete historical undo export."""
from pathlib import Path
import json
from project_paths import PROJECT_ROOT, SOURCE_ROOT
def memory_calls(root=SOURCE_ROOT):
    historical=json.loads((root.parent / 'recovery/evidence/memory_calls.json').read_text(encoding='utf-8'))
    complete=json.loads((root.parent / 'recovery/evidence/runtime/undo_calls.json').read_text(encoding='utf-8'))['calls']
    old_undo={r['instruction_va'] for r in historical if r['function_va']==0x414E40 and r['api']=='WriteProcessMemory'}
    new_undo={r['instruction_va'] for r in complete}
    if len(new_undo)!=len(complete) or not old_undo<=new_undo: raise ValueError('Undo evidence regressed or duplicated')
    rows=[]
    for row in historical:
        if row['function_va']==0x414E40 and row['api']=='WriteProcessMemory': continue
        rows.append(dict(row,evidence_source='evidence/memory_calls.json'))
    rows.extend(dict(row,evidence_source='evidence/runtime/undo_calls.json') for row in complete)
    rows.sort(key=lambda r:(r['function_va'],r['instruction_va']))
    keys=[(r['function_va'],r['instruction_va'],r['api']) for r in rows]
    if len(keys)!=len(set(keys)): raise ValueError('Duplicate call evidence')
    return rows
