#pragma once
#include <cstddef>
#include <cstdint>
#include <limits>
#include <stdexcept>

// Subtract before comparing: neither address+length nor count*stride may wrap.
inline size_t imageRecordBytes2026(size_t count, size_t stride) {
    if (stride && count > (std::numeric_limits<size_t>::max)() / stride)
        throw std::out_of_range("image record size");
    return count * stride;
}

template<class Byte> class ImageRegion2026 final {
    static_assert(sizeof(Byte) == 1, "image regions address bytes");
public:
    ImageRegion2026(Byte* bytes, size_t size, std::uintptr_t origin)
        : bytes_(bytes), size_(size), origin_(origin) {}
    Byte* at(std::uintptr_t address, size_t length) const {
        if (address < origin_) throw std::out_of_range("image address");
        const auto offset = address - origin_;
        if (offset > size_ || length > size_ - offset)
            throw std::out_of_range("image range");
        return bytes_ + offset;
    }
private:
    Byte* bytes_;
    size_t size_;
    std::uintptr_t origin_;
};
