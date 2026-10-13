# San9 Companion

《三国志 9》优化伴侣的 Win32（x86）工程，以 2026 年 2 月版优化伴侣为基线。界面使用 Windows 原生控件，不依赖 MFC。

支持参数、武将、都市、兵法和阵型配置的编辑与应用；运行时负责游戏进程连接、注入和恢复。

## 下载与运行

- **发布包**：在 [Releases](https://github.com/cdd1037/san9-companion/releases) 下载由 `v*` 标签发布的 `San9Companion-<标签>-win-x86.zip`。
- **自动构建**：在 [Publish Windows x86](https://github.com/cdd1037/san9-companion/actions/workflows/publish.yml) 的成功运行记录中下载 `San9Companion-Publish-win-x86`，构建产物保留 30 天。

解压后运行 `San9Companion.exe`。五份默认配置 `San9PKHard*.txt` 与 EXE 放在同一目录；程序偏好保存在同目录的 `San9PKHardSettings.ini`。配置说明见 [配置文档](docs/configuration.md)。

## 从源码构建

环境：Windows、Visual Studio C++ v145、Windows SDK、Git、Python 3.10+；目标架构为 x86。

打开 `San9Companion.sln`，或在 PowerShell 中执行：

```powershell
./Build.ps1                         # Debug 构建
./Build.ps1 -Configuration Publish  # 发布构建
./Verify.ps1 -Runtime               # 静态检查、离线测试与界面检查
```

Debug 产物位于 `build/app/Debug/San9Companion.exe`。其他构建和验证命令见 [开发与验证](docs/development.md)。

## 项目结构

| 路径 | 内容 |
| --- | --- |
| `src/app/` | Win32 界面与应用服务 |
| `src/runtime/` | 游戏会话、注入、恢复与快照 |
| `src/model/` | 配置解析与数据模型 |
| `src/generated/` | 构建使用的固定数据 |
| `assets/` | 默认配置、图标与界面资源 |
| `build-config/` | MSBuild 项目与编译配置 |
| `tests/`、`tools/` | 离线测试、构建与验证工具 |
| `docs/` | 架构、配置及开发文档 |
| `recovery/` | 固定数据再生所需输入与证据 |

更多说明：[架构](docs/architecture.md) · [运行时](docs/runtime.md) · [恢复资料](recovery/README.md) · [开发约定](CONTRIBUTING.md)
