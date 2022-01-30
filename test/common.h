#pragma once
#include <string>
#include <vector>

namespace nepali {
namespace test {
const auto romanized_chars = std::vector<std::string>{
    "a", "b", "c",  "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n",
    "o", "p", "q",  "r", "s", "t", "u", "v", "w", "x", "y", "z", "A", "B",
    "C", "D", "E",  "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P",
    "Q", "R", "S",  "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3",
    "4", "5", "6",  "7", "8", "9", "^", "`", "~", "_", "+", "=", "[", "{",
    "]", "}", "\\", "|", "<", ".", ">", "/", "?"};

const auto expected_nepali_chars = std::vector<std::wstring>{
    std::wstring{0x093E}, std::wstring{0x092C}, std::wstring{0x091B},
    std::wstring{0x0926}, std::wstring{0x0947}, std::wstring{0x0909},
    std::wstring{0x0917}, std::wstring{0x0939}, std::wstring{0x093F},
    std::wstring{0x091C}, std::wstring{0x0915}, std::wstring{0x0932},
    std::wstring{0x092E}, std::wstring{0x0928}, std::wstring{0x094B},
    std::wstring{0x092A}, std::wstring{0x091F}, std::wstring{0x0930},
    std::wstring{0x0938}, std::wstring{0x0924}, std::wstring{0x0941},
    std::wstring{0x0935}, std::wstring{0x094C}, std::wstring{0x0921},
    std::wstring{0x092F}, std::wstring{0x0937}, std::wstring{0x0906},
    std::wstring{0x092D}, std::wstring{0x091A}, std::wstring{0x0927},
    std::wstring{0x0948}, std::wstring{0x090A}, std::wstring{0x0918},
    std::wstring{0x0905}, std::wstring{0x0940}, std::wstring{0x091D},
    std::wstring{0x0916}, std::wstring{0x0933}, std::wstring{0x0902},
    std::wstring{0x0923}, std::wstring{0x0913}, std::wstring{0x092B},
    std::wstring{0x0920}, std::wstring{0x0943}, std::wstring{0x0936},
    std::wstring{0x0925}, std::wstring{0x0942}, std::wstring{0x0901},
    std::wstring{0x0914}, std::wstring{0x0922}, std::wstring{0x091E},
    std::wstring{0x090B}, std::wstring{0x0966}, std::wstring{0x0967},
    std::wstring{0x0968}, std::wstring{0x0969}, std::wstring{0x096A},
    std::wstring{0x096B}, std::wstring{0x096C}, std::wstring{0x096D},
    std::wstring{0x096E}, std::wstring{0x096F}, std::wstring{0x005E},
    std::wstring{0x093D}, std::wstring{0x093C}, std::wstring{0x0952},
    std::wstring{0x200C}, std::wstring{0x200D}, std::wstring{0x0907},
    std::wstring{0x0908}, std::wstring{0x090F}, std::wstring{0x0910},
    std::wstring{0x0950}, std::wstring{0x0903}, std::wstring{0x0919},
    std::wstring{0x0964}, std::wstring{0x0965}, std::wstring{0x094D},
    std::wstring{0x003F}};
} // namespace test
} // namespace nepali