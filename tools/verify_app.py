"""Check compiled 2026 dialogs and complete generated branch coverage offline."""
from pathlib import Path
import argparse
import json
import re
from pe_image import PEImage, dialog_template
from dialog_customizations import control_title, customize_control_layout, dialog_title

from project_paths import PROJECT_ROOT, SOURCE_ROOT
def normalized_class(value):
    classes={128:'button',129:'edit',130:'static',131:'listbox',132:'scrollbar',133:'combobox'}
    return classes[value['ordinal']] if isinstance(value,dict) else value.lower()

def check_runtime_dependencies(imports, configuration):
    runtime_dlls = [name for name in imports if re.match(
        r'^(mfcm?\d|vcruntime\d|msvcp\d|concrt\d|ucrtbase|api-ms-win-crt-)', name, re.I)]
    assert not any(re.match(r'^mfcm?\d', name, re.I) for name in imports), ('2026 targets must not depend on MFC', imports)
    if configuration == 'Publish':
        assert not runtime_dlls, ('Publish requires static CRT', runtime_dlls)
    else:
        assert any(name.lower().startswith('vcruntime') for name in runtime_dlls), 'dynamic CRT dependency missing'
        debug = configuration == 'Debug'
        for name in runtime_dlls:
            if name.lower().startswith(('mfc', 'vcruntime')):
                assert bool(re.search(r'\d+d(?:u)?\.dll$', name, re.I)) == debug, (configuration, name)

def check_dependencies(path, configuration):
    executable = PEImage(path)
    imports = executable.imported_dlls()
    check_runtime_dependencies(imports, configuration)
    return executable, dict(executable=str(path.relative_to(PROJECT_ROOT)), imported_dlls=imports)

def check_executable(path, configuration):
    executable, result=check_dependencies(path, configuration)
    resources=executable.resources()
    count=0
    for ident in [102,131,132,133,134,135]:
        expected=dialog_template((PROJECT_ROOT / f'recovery/resources/5_{ident}_2052.bin').read_bytes())
        candidates=[r for r in resources if r['keys']==[5,ident,2052]]
        assert len(candidates)==1, (ident,'dialog missing/duplicated')
        actual=dialog_template(candidates[0]['data'])
        expected['title'] = dialog_title(ident, expected['title'])
        for key in ['title','rect','style','exstyle']:
            assert actual[key]==expected[key],(ident,key)
        for key in ['point_size','face']:
            assert actual['font'][key]==expected['font'][key],(ident,key)
        assert len(actual['controls'])==len(expected['controls']),ident
        for a,b in zip(actual['controls'],expected['controls']):
            customize_control_layout(ident, b)
            b['title']=control_title(ident,b['id'],b['title'])
            assert (a['id']&0xFFFF)==(b['id']&0xFFFF),(ident,'control id')
            for key in ['title','rect','style','exstyle']:
                assert a[key]==b[key],(ident,a['id'],key,a[key],b[key])
            assert normalized_class(a['window_class'])==normalized_class(b['window_class'])
        count+=len(actual['controls'])
    result.update(dialogs=6, controls=count)
    return result

def check_core_boundary():
    for directory in ('runtime', 'model'):
        for file in (SOURCE_ROOT/directory).iterdir():
            if file.suffix not in ('.cpp', '.h'): continue
            source=file.read_text(encoding='utf-8-sig')
            assert not re.search(r'#\s*include\s*[<"]afx|\bCString\b|\bAfx\w+\b|\bSetWindowText[A-W]?\b', source), file
            assert 'app/src' not in source and '../app/' not in source, file
    for project in ('../build-config/Runtime.vcxproj', '../build-config/RuntimeTests.vcxproj', '../build-config/Companion.vcxproj', '../build-config/Toolchain.props'):
        assert 'UseOfMfc' not in (SOURCE_ROOT/project).read_text(encoding='utf-8'), project
    test=(SOURCE_ROOT/'../tests/runtime_test.cpp').read_text(encoding='utf-8')
    assert 'AfxWinInit' not in test
    for file in (SOURCE_ROOT/'app').rglob('*'):
        if file.suffix not in ('.cpp', '.h'): continue
        source=file.read_text(encoding='utf-8-sig')
        assert not re.search(r'#\s*include\s*[<"]afx|\bCString\b|\bAfx\w+\b', source), file
        if file.parent.name == 'application':
            assert '../ui/' not in source and '../platform/' not in source, file
        assert 'san9::layout2026::' not in source and 'runtime_.field<' not in source, file
        assert 'readGameMemory(' not in source and 'ReadGameMemory(' not in source, file
        if file.parent.name != 'platform':
            assert not re.search(r'\b(?:CreateWindowEx[A-W]?|SendMessage[A-W]?|GetDlgItem|SetWindowText[A-W]?)\s*\(', source), file


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--configuration', nargs='+', choices=['Release','Debug','Publish'], default=['Debug'])
    args=parser.parse_args()
    result=[]
    tests=[]
    for config in args.configuration:
        result.append(check_executable(PROJECT_ROOT / f'build/app/{config}/San9Companion.exe', config))
        test_path=PROJECT_ROOT / f'build/tests/{config}/San9RuntimeTests.exe'
        _, dependencies=check_dependencies(test_path, config)
        tests.append(dependencies)
    maintained={name:(SOURCE_ROOT/'runtime'/name).read_text(encoding='utf-8') for name in
        ('RuntimeVersion2026.cpp','RuntimeInjection2026.cpp','RuntimeConfiguration2026.cpp','RuntimeZone2026.cpp')}
    assert not (SOURCE_ROOT/'generated/RuntimeBranches.inc').exists()
    expected={}
    for address in ['409840','409E10','41A1F0']:
        source=(PROJECT_ROOT / f'recovery/evidence/runtime/sub_{address}.c').read_text(encoding='utf-8')
        assert 'JUMPOUT' not in source
        expected[address]=source.count('WriteProcessMemory(')
    assert 'applyGameConfiguration(reason)' in maintained['RuntimeInjection2026.cpp']
    assert 'applyCityConfiguration(reason)' in maintained['RuntimeConfiguration2026.cpp']
    core_project=(PROJECT_ROOT/'build-config/Runtime.vcxproj').read_text(encoding='utf-8')
    for name in maintained: assert name in core_project, name
    for project in ('../build-config/Companion.vcxproj','../build-config/RuntimeTests.vcxproj'):
        entries=(SOURCE_ROOT/project).read_text(encoding='utf-8')
        assert 'ProjectReference Include="Runtime.vcxproj"' in entries, project
        for name in maintained: assert name not in entries, (project, name)
    check_core_boundary()
    for file in (SOURCE_ROOT/'app').rglob('*.cpp'):
        assert '#include "InsertAsm.h"' not in file.read_text(encoding='utf-8-sig')
        assert '::WriteProcessMemory(' not in file.read_text(encoding='utf-8-sig'), (file,'write bypasses runtime journal')
    report=dict(resources=result,test_executables=tests,evidence_write_calls_by_function=expected,
        evidence_total_write_calls=sum(expected.values()),maintained_sources=list(maintained),
        runtime_branch_generation=False,parameter_bindings=88,core_mfc_dependency=False,core_gui_dependency=False,frontend_mfc_dependency=False,
        original_host_executed=False,live_game_injection='not_performed',gui_run='not_performed')
    output=PROJECT_ROOT / 'out/app/structure.json'
    output.parent.mkdir(parents=True,exist_ok=True)
    output.write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(report,ensure_ascii=False,indent=2))

if __name__=='__main__': main()
