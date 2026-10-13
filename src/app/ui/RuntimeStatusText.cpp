#include "RuntimeStatusText.h"
#include <sstream>
#include <iomanip>
namespace app
{
static std::wstring primaryStatusText(const RuntimeStatus2026 &s)
{
    switch (s.kind)
    {
    case RuntimeStatusKind2026::None:
        return L"";
    case RuntimeStatusKind2026::Connected:
        return L"正在监控游戏(" + std::to_wstring(s.errorCount) + L")" + std::wstring(s.activityDots, L'·');
    case RuntimeStatusKind2026::WaitingForGame:
        return L"找不到游戏窗口!";
    case RuntimeStatusKind2026::UnsupportedVersion:
        return L"不支持游戏的当前版本!";
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
namespace {
const wchar_t* operationText(RuntimeOperation2026 operation) {
    switch (operation) {
    case RuntimeOperation2026::None: return L"";
    case RuntimeOperation2026::ResolveProcess: return L"查找进程";
    case RuntimeOperation2026::OpenProcess: return L"打开进程";
    case RuntimeOperation2026::CaptureIdentity: return L"读取进程身份";
    case RuntimeOperation2026::VerifyProcess: return L"确认进程身份与存活状态";
    case RuntimeOperation2026::VerifyWindow: return L"确认游戏窗口";
    case RuntimeOperation2026::RegisterMessage: return L"注册游戏通知";
    case RuntimeOperation2026::CloseProcess: return L"关闭进程句柄";
    case RuntimeOperation2026::ClosePendingChanges: return L"检查句柄释放顺序";
    case RuntimeOperation2026::Allocate: return L"分配补丁内存";
    case RuntimeOperation2026::QueryProtection: return L"查询内存保护";
    case RuntimeOperation2026::ValidateProtection: return L"检查内存区域";
    case RuntimeOperation2026::Protect: return L"修改内存保护";
    case RuntimeOperation2026::Read: return L"读取游戏内存";
    case RuntimeOperation2026::ReadOriginal: return L"保存原始字节";
    case RuntimeOperation2026::Write: return L"写入补丁";
    case RuntimeOperation2026::Flush: return L"刷新指令缓存";
    case RuntimeOperation2026::RestoreBytes: return L"恢复原始字节";
    case RuntimeOperation2026::RestoreFlush: return L"刷新恢复后的指令缓存";
    case RuntimeOperation2026::RestoreProtection: return L"恢复内存保护";
    case RuntimeOperation2026::ReleaseAllocation: return L"释放补丁内存";
    case RuntimeOperation2026::CloseExitedProcess: return L"清理已退出进程句柄";
    case RuntimeOperation2026::RuntimeException: return L"运行时异常";
    }
    return L"未知操作";
}
std::wstring failureText(const RuntimeFailure2026& failure) {
    std::wostringstream text;
    text << operationText(failure.operation);
    if (failure.target) text << L"，地址 0x" << std::uppercase << std::hex
        << std::setfill(L'0') << std::setw(8) << failure.target << std::dec;
    switch (failure.operation) {
    case RuntimeOperation2026::Read:
    case RuntimeOperation2026::ReadOriginal:
    case RuntimeOperation2026::Write:
    case RuntimeOperation2026::Flush:
    case RuntimeOperation2026::RestoreBytes:
    case RuntimeOperation2026::RestoreFlush:
        text << L"，传输 " << failure.transferred << L"/" << failure.requested << L" 字节";
        break;
    default:
        if (failure.requested) text << L"，范围 " << failure.requested << L" 字节";
        break;
    }
    if (failure.systemError) text << L"，系统错误 " << failure.systemError;
    return text.str();
}
}
std::wstring statusText(const RuntimeStatus2026& status) {
    return primaryStatusText(status);
}
std::wstring statusDetails(const RuntimeStatus2026& status) {
    auto text = primaryStatusText(status);
    if (status.failure) text += L" 原因：" + failureText(status.failure) + L"。";
    if (status.recoveryFailure) text += L" 恢复失败：" + failureText(status.recoveryFailure) + L"。";
    return text;
}
} // namespace app
