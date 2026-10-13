# 开发与验证

根目录 `San9Companion.sln` 包含应用、核心静态库和离线测试。MSBuild 配置统一放在 `build-config/`，构建脚本放在 `tools/`。三个配置都是 x86：Release/Debug 使用对应动态 CRT，Publish 使用静态 CRT；所有当前目标禁止 MFC 依赖，所有配置默认关闭编译器和链接器 PDB 输出。脚本默认使用 Debug，日常只用 Debug 构建与测试；其他配置按需显式指定。CMake 需要 3.25 或更新版本。

```powershell
./Build.ps1 -Configuration Debug -OfflineTests -UiSmoke
./Verify.ps1 -Runtime
./Verify.ps1 -Native
```

应用输出到 `build/app/<配置>/San9Companion.exe`，核心到 `build/runtime/<配置>/San9Runtime.lib`，离线测试到 `build/tests/<配置>/San9RuntimeTests.exe`。中间文件集中在 `build/obj/`，验证报告集中在 `out/`。

应用编译前由 `tools/Write-BuildInfo.ps1` 读取当前 Git 提交的 committer 时间，转换为 UTC+8，生成 `$(IntDir)/BuildInfo.h`。生成文件只在内容变化时重写，不入库；直接用 Visual Studio 或 MSBuild 构建也会执行。此显示代表提交时间，未提交的本地改动不会更新它；构建应用需要 Git 和含提交记录的工作区。

`.github/workflows/publish.yml` 使用 Windows Server 2025 / Visual Studio 2026 runner 构建 x86 Publish，仅上传 EXE 和五份配置 TXT。触发方式为推送 main、推送 v* 标签或手动运行；不运行测试，不创建 GitHub Release。失败时保留 MSBuild 日志。

`--ui-smoke` 创建隐藏的主窗口和编辑窗口，检查参数绑定、分页、单选组、条目切换保存和草稿隔离。该模式不轮询或连接游戏、不读取个人配置、不写 INI，也不打开文件对话框。它不代替可见界面和实机验收。

CMake 在 x86 Windows 环境构建模型、核心与离线测试，不构建 GUI：

```powershell
cmake -S . -B build/cmake-x86 -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build/cmake-x86
ctest --test-dir build/cmake-x86 --output-on-failure
```

其他平台或 x64 仅启用纯模型目标。日常构建不需要 IDA；再生固定数据需要 `recovery/` 中保留的输入和证据。生成器不会覆盖手工注入逻辑。

测试和工具按职责命名，避免维护旧版兼容入口。源码相对包含路径、项目引用、脚本入口和文档链接必须随移动同步调整。维护时不计算文件哈希，字节内容可直接比较。
