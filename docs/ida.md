# IDA

普通构建与测试不需要 IDA。仅在重新导出原始样本或核对游戏侧指令时使用。

工作区样本：`recovery/sample-2026/San9PKHard.exe`。本机数据库保留在同目录并由 Git 忽略。移动旧数据库后，确认 IDA 中的输入路径指向当前样本位置；导出工具会检查目标路径，不能用另一份同名 EXE 替代。

```powershell
./tools/Start-IdaMcp.ps1
./tools/Start-IdaMcp.ps1 -Database ./recovery/sample-2026/San9PKHard.exe -Background
```

工具默认使用本机 `uvx` 和 `ida-mcp`，监听 `127.0.0.1:8737`。端口、数据库位置和后台启动可通过脚本参数指定。本机 Python 环境使用用户设置的 `IDAPYTHON_VENV_EXECUTABLE`，不修改仓库源码。

IDA 内执行 `tools/export_ida.py`、`export_runtime_ida.py`、`export_payload_disassembly.py` 或 `export_undo_calls_ida.py`，输出到 `recovery/evidence/`。这些工具不执行原 EXE 或游戏注入；具体指令分类修复以脚本中的地址及原字节检查为准，不自动保存数据库。

固定资料再生使用 `tools/reconstruct.py` 和 `recover_runtime.py`，验证使用 `tools/verify.py`。源码维护与字节证据应区分；逆向伪代码不是可编译源码。
