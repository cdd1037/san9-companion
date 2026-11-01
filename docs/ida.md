# IDA工作规范

普通构建与测试不需要IDA。只有重新导出样本、检查注入字节或核对原游戏语义时才使用。功能说明见[功能与采用方案](companion-2026.md)、[AI设计](companion-ai.md)和[算法参考](optimizations.md)。

## 数据库与输入

| 对象 | 位置与用途 |
| --- | --- |
| 伴侣样本 | `recovery/sample-2026/San9PKHard.exe`，用于导出载荷、描述符和恢复数据 |
| 原游戏主库 | 相邻remake的`research/analysis/San9PK-TC-101.i64`，用于核对原版函数、字段和调用关系 |
| 主库当前输入 | `C:/home/game/san9/San9 Tc/San9PK.exe`，x86、基址`0x400000` |

本机数据库由Git忽略。按数据库的明确路径连接已有会话；每次操作先核对数据库路径、输入文件、架构和基址。输入为空、基址异常或身份不符时停止写入，不对空会话保存。移动数据库后应更新输入路径，再通过相关函数字节和原有注释确认身份。

## 启动与导出

```powershell
./tools/Start-IdaMcp.ps1
./tools/Start-IdaMcp.ps1 -Database ./recovery/sample-2026/San9PKHard.exe -Background
```

仓库脚本使用本机`uvx`和`ida-mcp`，默认监听`127.0.0.1:8737`；数据库、端口和后台启动方式由参数指定。Python环境使用用户设置的`IDAPYTHON_VENV_EXECUTABLE`。

在IDA内按需要执行：

| 工具 | 输出用途 |
| --- | --- |
| `tools/export_ida.py` | 样本函数与数据 |
| `tools/export_runtime_ida.py` | 注入安装及运行时逻辑 |
| `tools/export_payload_disassembly.py` | 注入字节的反汇编 |
| `tools/export_undo_calls_ida.py` | 恢复调用依据 |

导出写入`recovery/evidence/`，不运行原EXE或游戏注入，也不自动保存数据库。固定资料再生使用`tools/reconstruct.py`与`recover_runtime.py`，验证使用`tools/verify.py`。

## 分析与标注

先确认实际安装目标和来源字节，再分析可达分支。恢复名、线性反汇编及反编译器推断只作导航；相对跳转应按游戏侧基准地址解码。注入区可能混有代码、数据和多个入口，不把整个缓冲区自动视为一个函数。

新增解释优先使用函数可重复注释，明确区分原版行为、伴侣改动和设计推断。保留原注释；没有独立依据时不改函数名、类型或边界，不将伴侣指令写进原版主库。

保存前回读注释，并比较相关函数的原始字节与去注释后的反编译正文；保存后确认持久化结果。只释放本次取得的连接，不终止其他会话。公开文档保存自行归纳的行为和定位信息，不收录大段原版反编译正文。不计算或记录文件哈希。

## 已保存的研究依据

原版主库已包含38条伴侣研究注释。相关操作只追加解释，未修改程序字节、函数名称、类型或边界。

| 范围 | 证据 |
| --- | --- |
| 经济、成长与战斗行为 | [行为注释及回读](../recovery/evidence/runtime/companion_behavior_annotations_20261031.json) |
| 任官、运输与反击编队 | [AI注释及回读](../recovery/evidence/runtime/companion_ai_annotations_20261031.json) |
| 兵法、船型、路线与协同 | [战术注释及回读](../recovery/evidence/runtime/companion_ai_tactics_annotations_20261031.json) |
| 接力登记、派遣与冷却 | [主库同步及回读](../recovery/evidence/runtime/companion_ai_relay_annotations_20261031.json) |
| 选阵、进攻、回撤与组织的设计意图 | [只读核对依据](../recovery/evidence/runtime/companion_ai_design_review_20261031.json) |

证据文件保留实际核对范围；当前行为与采用建议在主题文档维护。
