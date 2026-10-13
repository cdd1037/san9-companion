#pragma once
#include <windows.h>
#include <filesystem>
#include <stdexcept>

namespace san9 {
inline std::filesystem::path executableFile(const wchar_t* name) {
    static const auto directory = [] {
        wchar_t module[32768]{};
        const DWORD length = GetModuleFileNameW(nullptr, module, _countof(module));
        if (!length || length >= _countof(module))
            throw std::runtime_error("cannot locate executable directory");
        return std::filesystem::path(module).parent_path();
    }();
    return directory / name;
}
}
