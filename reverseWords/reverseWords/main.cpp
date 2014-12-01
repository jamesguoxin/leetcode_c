//
//  main.cpp
//  reverseWords
//
//  Created by Xin Guo on 05/11/14.
//  Copyright (c) 2014 JamesGuo. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
class Solution {
public:
    void reverseWords(std::string &s) {
        size_t length = s.size();
        size_t index = 0;
        std::string tmp;
        s = reverseString(s);
        for (size_t i = 0; i < length; i++) {
            if (s[i] == ' ' || i == length - 1) {
                if (i != length - 1) {
                    tmp = s.substr(index, i - index);
                    tmp = reverseString(tmp);
                    s.replace(index, i - index, tmp);
                    index = i + 1;
                } else {
                    tmp = s.substr(index, i + 1 - index);
                    tmp = reverseString(tmp);
                    s.replace(index, i + 1 - index, tmp);
                    index = i + 1;
                }
            }
        }
        // Special case check, there should be no spaces in the beginning and end of the result string
        while (s[0] == ' ' || s[s.size() - 1] == ' ') {
            if (s[0] == ' ') {
                s.erase(0, 1);
            }
            
            if (s[s.size() - 1] == ' ') {
                s.pop_back();
            }
        }
        // Special case check, there should be no more than one space between words
        std::vector<size_t> mark;
        if (!s.empty()) {
            if (s.size() > 1) {
                for (size_t i = 1; i < s.size(); i++) {
                    char cur = s[i];
                    char pre = s[i - 1];
                    if (cur == ' ' && pre == ' ') {
                        mark.push_back(i-1);
                    }
                }
                
                for (size_t i = 0; i < mark.size(); i++){
                    s.erase(mark[i] - i, 1);
                }
            }
        }
        
    }
    
    std::string reverseString(std::string s) {
        size_t length = s.size();
        char tmp;
        if (length > 1) {
            if (length % 2 == 0) {
                for (size_t i = 0; i < length / 2; i++) {
                    tmp = s[i];
                    s[i] = s[length - 1 - i];
                    s[length - 1 - i] = tmp;
                }
            } else {
                for (size_t i = 0; i < (length - 1) / 2; i++) {
                    tmp = s[i];
                    s[i] = s[length - 1 - i];
                    s[length - 1 - i] = tmp;
                }
            }
        }
        return s;
    }
};


int main(int argc, const char * argv[]) {
    std::string s("   a   b ");
    Solution solution;
    solution.reverseWords(s);
    std::cout << s << std::endl;
    return 0;
}
