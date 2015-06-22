//
//  main.cpp
//  letterComb
//
//  Created by Xin Guo on 16/06/15.
//  Copyright (c) 2015 JamesGuo. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> maps {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        
        res = letterCombHelper(digits, maps, 0);
        return res;
        
    }
    
    vector<string> letterCombHelper(string& digits, vector<string>& maps, int depth) {
        vector<string> res;
        vector<string> res1;
        string s;
        int position = digits[depth] - '0';
        
        if (depth == int(digits.size()) - 1) {
            for (int i = 0; i < maps[position].size(); i++) {
                s = "";
                s.insert(0, 1, maps[position][i]);
                res.push_back(s);
            }
            return res;
        } else {
            res = letterCombHelper(digits, maps, depth + 1);
            for (int i = 0; i < maps[position].size(); i++) {
                for (int j = 0; j < res.size(); j++) {
                    s = res[j];
                    s.insert(0, 1, maps[position][i]);
                    res1.push_back(s);
                }
            }
            return res1;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution check;
    vector<string> res = check.letterCombinations("23");
    for (size_t i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}
