#include "PatchImage.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

int main(int argc, char** argv) {
    try {
        if (argc > 3) throw std::invalid_argument("usage: san9-static [base] [output.bin]");
        const std::string text = argc > 1 ? argv[1] : "0x10000000";
        std::size_t used = 0;
        const auto number = std::stoull(text, &used, 0);
        if (used != text.size() || number > 0xFFFFFFFFULL)
            throw std::invalid_argument("base must fit uint32");
        san9::PatchImage image;
        const auto changes = image.rebase(static_cast<std::uint32_t>(number));
        if (argc == 3) {
            std::ofstream out(argv[2], std::ios::binary);
            out.write(reinterpret_cast<const char*>(image.data().data()), image.data().size());
            if (!out) throw std::runtime_error("could not write output");
        }
        std::cout << "Offline model, base=0x" << std::hex << image.base() << std::dec
                  << ", relocation entries=" << changes.size() << "\n";
        return 0;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }
}
