#include "ConfigFileText.h"
namespace app
{
std::wstring configFileText(const ConfigFileResult &result)
{
    const wchar_t *reason = L"";
    switch (result.error)
    {
    case ConfigFileError::none: return {};
    case ConfigFileError::missingFile: reason = L"配置文件不存在"; break;
    case ConfigFileError::openFailed: reason = L"无法打开配置文件"; break;
    case ConfigFileError::missingLine: reason = L"配置缺少数据行"; break;
    case ConfigFileError::invalidInteger: reason = L"数据不是有效整数"; break;
    case ConfigFileError::integerOverflow: reason = L"整数超出存储范围"; break;
    case ConfigFileError::outOfRange: reason = L"字段超出允许范围或分隔点顺序错误"; break;
    case ConfigFileError::extraData: reason = L"配置包含多余数据"; break;
    case ConfigFileError::readFailed: reason = L"读取配置失败"; break;
    case ConfigFileError::invalidConfig: reason = L"配置无效，无法保存"; break;
    case ConfigFileError::createFailed: reason = L"无法在目标目录创建临时文件"; break;
    case ConfigFileError::writeFailed: reason = L"写入配置失败"; break;
    case ConfigFileError::flushFailed: reason = L"刷新配置文件失败"; break;
    case ConfigFileError::closeFailed: reason = L"关闭配置文件失败"; break;
    case ConfigFileError::replaceFailed: reason = L"替换配置文件失败，请检查文件是否被占用或只读"; break;
    }
    std::wstring text = reason;
    if (result.line) text += L"，第 " + std::to_wstring(result.line) + L" 行";
    if (result.systemError) text += L"（系统错误 " + std::to_wstring(result.systemError) + L"）";
    text += L"。已保留原配置。";
    if (result.cleanupSystemError)
        text += L"清理临时文件时发生错误（系统错误 " + std::to_wstring(result.cleanupSystemError) +
                L"）：" + result.temporaryFile.wstring() + L"。";
    return text;
}
}
