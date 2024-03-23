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

    std::vector<std::pair<std::string, std::string>> data_capitalize_first = {
            { "4ba ba Dt", "4ba Ba Dt" }
    };

    std::vector<std::pair<std::string, int>> data_count_vowels = {
            { "a ba Dt", 2 },
            { "lrm", 0 }
    };

    std::vector<std::pair<std::string, int>> data_sum_digits = {
            { "Lo67m 1p7um", 75 }
    };

    std::vector<std::pair<std::pair<std::string, std::string>, int>> data_search_substr = {
            {{"This is a test string", "test"}, 10}
    };

    Color::Modifier green(Color::FG_GREEN);
    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);

    for (const auto & data : data_reverse) {
        auto out = reverse(data.first);
        
        if (out != data.second) {
            std::cout << red << "reverse    : Test failed for INPUT: " << data.first << "  OUTPUT: " << data.second << def <<'\n';
        } else {
            std::cout << green << "reverse    : Test succeed for INPUT: " << data.first << "  OUTPUT: " << data.second << def << '\n';
        }
    }

    std::cout << std::endl;

    for (const auto & data : data_capitalize_first) {

        auto out = first_to_upper(data.first);

        if (out != data.second) {
            std::cout << red << "first_to_upper    : Test failed for INPUT: " << data.first << "  OUTPUT: " << data.second << def <<'\n';
        } else {
            std::cout << green << "first_to_upper    : Test succeed for INPUT: " << data.first << "  OUTPUT: " << data.second << def << '\n';
        }
    }

    std::cout << std::endl;

    for (const auto & data : data_count_vowels) {
        auto out = count_vowels(data.first);

        if (out != data.second) {
            std::cout << red << "count_vowels    : Test failed for INPUT: " << data.first << "  OUTPUT: " << data.second << def <<'\n';
        } else {
            std::cout << green << "count_vowels    : Test succeed for INPUT: " << data.first << "  OUTPUT: " << data.second << def << '\n';
        }
    }

    std::cout << std::endl;

    for (const auto & data : data_sum_digits) {
        auto out = sum_digits(data.first);

        if (out != data.second) {
            std::cout << red << "sum_digits    : Test failed for INPUT: " << data.first << "  OUTPUT: " << data.second << def <<'\n';
        } else {
            std::cout << green << "sum_digits    : Test succeed for INPUT: " << data.first << "  OUTPUT: " << data.second << def << '\n';
        }
    }

    std::cout << std::endl;

    for (const auto & data : data_search_substr) {
        auto func_args = data.first;
        auto out = search_substr(func_args.first, func_args.second);

        if (out != data.second) {
            std::cout << red << "search_substr    : Test failed for INPUT: " << "(\"" << func_args.first << "\"" << ", \"" << func_args.second << "\")" << "  OUTPUT: " << data.second << def <<'\n';
        } else {
            std::cout << green << "search_substr    : Test succeed for INPUT: "<< "(\"" << func_args.first << "\"" << ", \"" << func_args.second << "\")" << "  OUTPUT: " << data.second << def << '\n';
        }
    }

    std::cout << std::endl;

    for (const auto & data : data_search_substr) {
        auto func_args = data.first;
        const char* first_arg_char_arr = func_args.first.c_str();
        const char* second_arg_char_arr = func_args.second.c_str();
        auto out = custom_search(first_arg_char_arr, second_arg_char_arr);


        if (out != data.second) {
            std::cout << red << "custom_search    : Test failed for INPUT: " << "(\"" << func_args.first << "\"" << ", \"" << func_args.second << "\")" << "  OUTPUT: " << data.second << def <<'\n';
        } else {
            std::cout << green << "custom_search    : Test succeed for INPUT: "<< "(\"" << func_args.first << "\"" << ", \"" << func_args.second << "\")" << "  OUTPUT: " << data.second << def << '\n';
        }
    }

    return 0;
}
