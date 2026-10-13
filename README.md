# San9 Companion

三国志9优化伴侣的 Win32 开发工程。当前 GUI、核心和离线测试均不依赖 MFC，GUI 使用原生控件，暂不引入 Direct 自绘。注入与恢复采用独立会话和修改日志，尚未完成真实游戏验收。

## 构建与验证

环境：Windows、Visual Studio C++ v145、Windows SDK、Python 3.10+。目标架构为 x86；CMake 检查另需 CMake/Ninja。打开根目录 `San9Companion.sln`，或在 PowerShell 执行：

```powershell
./Build.ps1                              # Debug 日常构建
./Build.ps1 -Configuration Publish       # 静态 CRT 发布构建
./Build.ps1 -OfflineTests -UiSmoke        # 完整离线回归与隐藏窗口检查
./Verify.ps1                             # Python 与离线重定位
./Verify.ps1 -Runtime                     # Debug 日常检查
./Verify.ps1 -AllConfigurations           # Release / Debug / Publish
./Verify.ps1 -Native                      # CMake 模型与运行时检查
```

所有配置默认不生成 PDB。日常构建和测试使用 Debug，Release/Publish 仅在显式指定时使用。

程序：`build/app/Debug/San9Companion.exe`。五份配置 TXT 与偏好 INI 按 EXE 所在目录定位；手动测试时保留自己的配置。隐藏窗口检查禁用游戏轮询和偏好写入，不连接游戏。实机注入及可见界面由用户验收。

## 目录

| 目录 | 内容 |
| --- | --- |
| `src/app/` | 应用服务、页面与 Win32 控件后端 |
| `src/runtime/` | 会话、注入、回滚、游戏事件与快照 |
| `src/model/` | 配置、快照与重定位值模型 |
| `src/generated/` | 构建使用的固定生成数据 |
| `assets/` | 默认配置、图标、控件 ID 和应用资源入口 |
| `build-config/` | MSBuild 项目与共用编译配置 |
| `tests/` | C++ 离线回归与 Python 证据检查 |
| `tools/` | 构建、验证、再生与 IDA 辅助工具 |
| `docs/` | 当前架构、配置及开发说明 |
| `recovery/` | 生成和验证必需的原始样本、输入和证据 |
| `build/`、`out/` | 本地编译产物、缓存和报告，不入库 |

旧 MFC 前端、2019 对照工程及历史开发文档已清理。保留的恢复资料具有明确生成/验证用途，不参与日常源码编译；说明见 [恢复资料](recovery/README.md)。原始材料的权利归原权利人，本整理不另行授予其许可证。

[架构](docs/architecture.md) · [运行时](docs/runtime.md) · [配置](docs/configuration.md) · [开发与验证](docs/development.md) · [IDA](docs/ida.md) · [开发约定](CONTRIBUTING.md)
