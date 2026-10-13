# 恢复资料

这些文件仍用于固定数据再生和独立证据验证，不是当前开发源码，也不是历史工程备份。

| 目录 | 用途 |
| --- | --- |
| `sample-2026/` | 唯一提供的原始 EXE，PE/字节/资源/版本及重定位验证依据；本机 IDA 数据库不入库 |
| `reference-2019/InsertAsm.h` | 原始标识、数组与字段恢复输入 |
| `reference-2019/San9PKHardDlg.cpp` | 原始构造初始化顺序和成员命名恢复输入 |
| `evidence/` | 反编译、汇编、对象、完整运行时调用与参数证据 |
| `resources/` | 原始资源字节和索引，用于再生与证据检查 |

旧版工程、迁移副本、帮助文档和未使用的原始工程文件已清理，只保留当前生成器和测试实际读取的输入。原始文件的字节和编码保持不变；证据内记录的旧绝对路径属于导出时的来源信息，不作为当前构建入口。

从仓库根目录运行：

```powershell
python tools/reconstruct.py
python tools/recover_runtime.py
python tools/verify.py
```

再生输出位于 `src/generated/`、`recovery/resources/` 和 `assets/ui/dialogs.rc`，不覆盖 `src/runtime/` 的手工逻辑。普通构建直接使用已入库生成数据，不需要 IDA。需要重新导出时见 [IDA](../docs/ida.md)。

原始样本与源码的权利归原权利人，本工程不另行授予其许可证。不计算或记录文件哈希；验证以结构、功能和直接字节内容比较完成。
