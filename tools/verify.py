"""Run offline verification and save a reviewable report."""
from pathlib import Path
from datetime import datetime, timezone
import io
import json
import shutil
import sys
import unittest

from project_paths import PROJECT_ROOT, SOURCE_ROOT
def main():
    suite = unittest.defaultTestLoader.discover(str(PROJECT_ROOT / 'tests'), pattern='test_*.py')
    log = io.StringIO()
    result = unittest.TextTestRunner(stream=log, verbosity=2).run(suite)
    report = dict(verified_at=datetime.now(timezone.utc).isoformat(), tests=result.testsRun,
                  successful=result.wasSuccessful(), failures=len(result.failures), errors=len(result.errors),
                  native_build_in_this_run='not_run',
                  native_build_reason='Python-only check; run Check-Native.ps1; current report: out/native/verification.json',
                  toolchain_on_path={name: bool(shutil.which(name)) for name in ('cmake','cl','clang++','g++')},
                  live_exe_injection='not_performed')
    out = PROJECT_ROOT / 'out'
    out.mkdir(exist_ok=True)
    (out/'verification.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    (out/'verification.txt').write_text(log.getvalue(),encoding='utf-8')
    print(log.getvalue())
    return 0 if result.wasSuccessful() else 1


if __name__ == '__main__':
    sys.exit(main())
