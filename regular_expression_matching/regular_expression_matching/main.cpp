//
//  main.cpp
//  regular_expression_matching
//
//  Created by Xin Guo on 01/06/15.
//  Copyright (c) 2015 JamesGuo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int size_s = int(s.size());
        int size_p = int(p.size());
        vector<vector<bool>> dp(size_s + 1, vector<bool>(size_p + 1, false));
        
        dp[0][0] = true;
        
        for (int i = 0; i <= size_s; i++) {
            for (int j = 1; j <= size_p; j++) {
                if (p[j - 1] != '.' && p[j - 1] != '*') {
                    if (i > 0 && s[i - 1] == p[j - 1] && dp[i - 1][j - 1]) {
                        dp[i][j] = true;
                    }
                } else if (p[j - 1] == '.') {
                    if (i > 0 && dp[i - 1][j - 1]) {
                        dp[i][j] = true;
                    }
                } else if (j > 1) { // '*' cannot be the 1st char
                    if (dp[i][j - 1] || dp[i][j - 2]) {
                        dp[i][j] = true;
                    } else if (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]) {
                        dp[i][j] = true;
                    }
                }
            }
        }
        return dp[size_s][size_p];
    }
};

int main(int argc, const char * argv[]) {
    string s = "aab";
    string p = "c*a*b";
    Solution check;
    bool result = check.isMatch(s, p);
    std::cout << "The matching is " << result << endl;
    return 0;
}
