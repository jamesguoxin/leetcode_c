//
//  main.cpp
//  wordbreak
//
//  Created by Xin Guo on 30/10/14.
//  Copyright (c) 2014 JamesGuo. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_set>

class Solution {
public:
    bool wordBreak(std::string s, std::unordered_set<std::string> &dict) {
        std::string tmp;
        size_t start = 0;
        for (size_t i = 0; i < s.length(); i++) {
            tmp = s.substr(start, (i - start + 1));
            if (dict.find(tmp) != dict.end()) {
                start = i + 1;
            }
        }
        
        if (start == s.length()) {
            return true;
        } else {
            return false;
        }
    }
    
    bool wordBreak1(std::string s, std::unordered_set<std::string> &dict) {
        size_t length = s.size();
        int record[length][length];
        for (size_t i = 0; i < length; i++) {
            for (size_t j = 0; j < length; j++) {
                record[i][j] = 0;
            }
        }
        
        for (size_t i = 0; i < length; i++) {
            for (size_t len = 1; len <= length; len++) {
                std::string tmp = s.substr(i, len);
                if (dict.find(tmp) != dict.end()) {
                    record[i][len - 1] = 1;
                    if (i > 0 && record[0][i - 1]) {
                        record[0][i + len - 1] = 1;
                    }
                }
            }
        }
        
        if (record[0][length - 1] == 0) {
            return false;
        } else {
            return true;
        }

    }
};

int main(int argc, const char * argv[]) {
    std::string s = "aaaaaaa";
    std::unordered_set<std::string> dict({"aaaa", "aa"});
    Solution solution;
    bool result;
    result = solution.wordBreak1(s, dict);
    std::cout << result << std::endl;
    return 0;
}
