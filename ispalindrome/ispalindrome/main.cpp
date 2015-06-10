//
//  main.cpp
//  ispalindrome
//
//  Created by Xin Guo on 27/05/15.
//  Copyright (c) 2015 JamesGuo. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10 && x >= 0) return true;
        int divi = 1;
        while (x / divi >= 10) {
            divi = divi * 10;
        }
        
        while (x != 0) {
            if (x % 10 != x / divi) return false;
            x = (x % divi) / 10;
            divi = divi / 100;
        }
        
        return true;
        
    }
};

int main(int argc, const char * argv[]) {
    Solution test;
    int x = 10021;
    bool result;
    result = test.isPalindrome(x);
    std::cout << result << std::endl;
    return 0;
}
