#pragma once
#include <Windows.h>
#include <cstddef>
namespace san9 {
enum class TextResult { success, invalidBuffer, unterminated, decodeFailed, mapFailed, encodeFailed, unrepresentable, insufficientCapacity };
struct TextApi {
    decltype(&::MultiByteToWideChar) decode=&::MultiByteToWideChar;
    decltype(&::LCMapStringW) simplify=&::LCMapStringW;
    decltype(&::WideCharToMultiByte) encode=&::WideCharToMultiByte;
};
// Bounded, atomic in-place conversion. No caller bytes change on failure.
TextResult simplifyGameText(char* text,size_t capacity,const TextApi& api=TextApi{});
}
