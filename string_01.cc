#include "string_01.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

auto main() -> int {
    string example_str;
    string example_substr;
    cout << "Enter text for main string:";
    cin >> example_str;

    cout << "Enter text for substring:";
    cin >> example_substr;

    cout << "`string_toys::reverse` call" << endl;
    cout << string_toys::reverse(example_str) << endl;

    cout << "`string_toys::first_to_upper` call" << endl;
    cout << string_toys::first_to_upper(example_str) << endl;

    cout << "`string_toys::count_vowels` call" << endl;
    cout << string_toys::count_vowels(example_str) << endl;

    cout << "`string_toys::sum_digits` call" << endl;
    cout << string_toys::sum_digits(example_str) << endl;

    cout << "`string_toys::search_substr` call" << endl;
    cout << string_toys::search_substr(example_str, example_substr) << endl;

    cout << "`string_toys:custom_search` call" << endl;
    cout << string_toys::custom_search(example_str.c_str(), example_substr.c_str()) << endl;
    return 0;
}