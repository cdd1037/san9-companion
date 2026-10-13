#include "RuntimeStatusText.h"
namespace app
{
std::wstring statusText(const RuntimeStatus2026 &s)
{
    switch (s.kind)
    {
    case RuntimeStatusKind2026::None:
        return L"";
    case RuntimeStatusKind2026::Connected:
        return L"正在监控游戏(" + std::to_wstring(s.errorCount) + L")" + std::wstring(s.activityDots, L'·');
    case RuntimeStatusKind2026::WaitingForGame:
        return L"找不到游戏窗口!";
    case RuntimeStatusKind2026::OpenFailed:
        return L"找不到游戏进程!";
    case RuntimeStatusKind2026::UnsupportedVersion:
        return L"不支持游戏的当前版本!";
    case RuntimeStatusKind2026::AllocationFailed:
        return L"分配优化补丁内存失败!!!";
    case RuntimeStatusKind2026::WriteFailed:
        return std::to_wstring(s.writeStage) + L" : error=" + std::to_wstring(s.systemError);
    case RuntimeStatusKind2026::ExitCleanupFailed:
        return L"游戏已退出，但句柄清理失败；稍后重试。";
    case RuntimeStatusKind2026::ProcessExited:
        return L"游戏已退出，旧会话已清理，等待重新连接。";
    case RuntimeStatusKind2026::IdentityUnavailable:
        return L"无法确认原游戏进程，已停止恢复并保留日志。";
    case RuntimeStatusKind2026::RecoveryRequired:
        return L"恢复未完成，已保留修改日志；请重试恢复。";
    case RuntimeStatusKind2026::Restored:
        return L"恢复已完成。";
    case RuntimeStatusKind2026::ModificationBlocked:
        return L"存在未完成的恢复，已停止修改；请先重试恢复。";
    case RuntimeStatusKind2026::ModificationRolledBack:
        return L"修改失败，本次修改已回滚。";
    case RuntimeStatusKind2026::ExceptionRolledBack:
        return L"运行时异常，本次修改已回滚。";
    }
    return L"";
}
} // namespace app
