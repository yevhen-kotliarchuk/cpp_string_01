#include "string_01.h"

#include <utility>
#include <vector>
#include <iostream>

using namespace string_toys;

#include <ostream>
namespace Color {
    enum Code {
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_BLUE     = 34,
        FG_DEFAULT  = 39,
        BG_RED      = 41,
        BG_GREEN    = 42,
        BG_BLUE     = 44,
        BG_DEFAULT  = 49
    };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}

auto main() -> int {

    std::vector<std::pair<std::string, std::string>> data_reverse = {
        { "abc", "cba" },
        { "xZz\nqwe", "ewq\nzZx" }
    };

    Color::Modifier green(Color::FG_GREEN);
    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);

    for (const auto & data : data_reverse) {
        auto out = reverse(data.first);
        
        if (out != data.second) {
            std::cout << red << "reverse    : Test failed for INPUT: " << data.first << "  OUTPUT: " << data.second << def <<'\n';
        } else {
            std::cout << green << "reverse    : Test failed for INPUT: " << data.first << "  OUTPUT: " << data.second << def << '\n';
        }
    }

    return 0;
}
