//
//  main.cpp
//  roman2int
//
//  Created by Xin Guo on 16/06/15.
//  Copyright (c) 2015 JamesGuo. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int value = 0;
        char pre = s[0];
        char current;
        value = value + c2n(pre);
        for (int index = 1; index < s.size(); index++) {
            current = s[index];
            
            if (c2n(current) > c2n(pre)) {
                value = c2n(current) - 2 * c2n(pre) + value;
            } else {
                value = c2n(current) + value;
            }
            pre = current;
        }
        
        return value;
    }
    
    int c2n(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
