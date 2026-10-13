#include "PatchImage.h"
#include <stdexcept>

void require(bool condition) { if (!condition) throw std::runtime_error("model invariant failed"); }
int main() {
    san9::PatchImage image;
    const auto original = image.data();
    const auto changes = image.rebase(0x10000000);
    require(changes.size() == 969);
    require(image.object32(3700) == 0x10004000);
    require(image.object32(7620) == 0x100031B0);
    require(image.read32(0x420107) == 0x100000D0);
    require(image.rebase(0x10000000).empty());
    image.rebase(0x20000000);
    require(image.object32(3700) == 0x20004000);
    image.rebase(0xA0000);
    require(image.data() == original);
    try { image.rebase(0); return 1; } catch (const std::invalid_argument&) {}
    return 0;
}
