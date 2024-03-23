#ifndef CPP_STRING_H
#define CPP_STRING_H

#include <string>
#include <iostream>

namespace string_toys {


auto reverse(const std::string & str) -> std::string {
    size_t str_len = str.length();
    std::string res_str;

    for(int i = 0; i < str_len; i++) {
        res_str += str[str_len - i - 1];
    }
    return res_str;
}

auto first_to_upper(const std::string & str) -> std::string {
    std::string res_str;
    for(int i = 0; i < str.length(); i++) {
        if(i == 0 && str[i] >= 'a' && str[i] <= 'z') {
            res_str += str[i] - 32;
            continue;
        }
        if(str[i - 1] == ' ' && str[i] >= 'a' && str[i] <= 'z') {
            res_str += str[i] - 32;
            continue;
        }
        res_str += str[i];
    }
    return res_str;
}

auto count_vowels(const std::string & str) -> int {
    char vowels_lower[] = {'a', 'e', 'i', 'o', 'u'};
    int counter = 0;
    for(char str_el : str) {
        for(char vowel_char : vowels_lower) {
            if(str_el == vowel_char || str_el == (vowel_char - 32)) {
                counter++;
            }
        }
    }
    return counter;
}

auto sum_digits(const std::string & str) -> int {
    int sum = 0;
    std::string tmp_num_str;
    for(char el: str) {
        if(el >= '0' && el <= '9') {
            tmp_num_str += el;
        } else if (!tmp_num_str.empty()) {
            sum += stoi(tmp_num_str);
            tmp_num_str.clear();
        }
    }
    return sum;
}

auto search_substr(const std::string & str, const std::string & substr) -> int {
    int position = -1;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == substr[0]) {
            position = i;
            for(int j = 1; j < substr.length(); j++) {
                if(str.length() <= j || str[i + j] != substr[j]) {
                    position = -1;
                    break;
                }
            }
            if(position != -1) {
                break;
            }
        }
    }
    return position;
}

auto custom_search(const char * str, const char * substr) -> int {
    int position = -1;
    int ref_index = 0;
    while(*str != '\0') {
        if(*str == *substr) {
            position = ref_index;
            str++;
            substr++;
            ref_index++;

            while(*substr != '\0' && *str != '\0') {
                if(*str == *substr) {
                    str++;
                    substr++;
                    ref_index++;
                    continue;
                } else {
                    position = -1;
                    break;
                }
            }
            if(position != -1) {
                break;
            }
        }
        str++;
        ref_index++;
    }
    return position;
}

}

#endif /* CPP_STRING_H */
