//
//  main.cpp
//  myatoi
//
//  Created by Xin Guo on 11/11/14.
//  Copyright (c) 2014 JamesGuo. All rights reserved.
//

#include <iostream>
#include <ctype.h>
class Solution {
public:
    int atoi(const char *str) {
        size_t i = 0;
        size_t length = strlen(str);
        if (length == 0) {
            return 0;
        }
        long long result = 0;
        bool is_positive = true;
        while(str[i] == ' ') {
            i = i + 1;
        }
        if (i == length) {
            return 0;
        }
        if (!isdigit(str[i]) && str[i] != '-' && str[i] != '+') {
            return 0;
        }
        if (str[i] == '-') {
            is_positive = false;
            i = i + 1;
        } else if (str[i] == '+') {
            i = i + 1;
        }
        if (!isdigit(str[i])) {
            return 0;
        }
        while (isdigit(str[i])) {
            result = 10 * result + (int)(str[i] - '0');
            if (is_positive && result > INT_MAX) {
                return INT_MAX;
            }
            
            if (!is_positive && -result < INT_MIN) {
                return INT_MIN;
            }
            i = i + 1;
        }
        if (is_positive) {
            return (int)result;
        } else {
            return (int)-result;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    const char str[100] = "    ";
    Solution s;
    int integer;
    integer = s.atoi(str);
    std::cout << integer << std::endl;
    return 0;
}
