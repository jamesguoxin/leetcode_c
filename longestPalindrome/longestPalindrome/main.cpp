//
//  main.cpp
//  longestPalindrome
//
//  Created by Xin Guo on 13/10/14.
//  Copyright (c) 2014 JamesGuo. All rights reserved.
//

#include <iostream>
#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        std::string option1;
        std::string option2;
        std::string result = "";
        std::string tmps;
        
        for (int i = 0; i < s.length(); i++) {
            option1 = longestPalinAtPositioni1(s, i);
            option2 = longestPalinAtPositioni2(s, i);
            
            if (option1.length() > option2.length()) {
                tmps = option1;
            } else {
                tmps = option2;
            }
            
            if (tmps.length() > result.length()) {
                result = tmps;
            }
            
        }
        return result;
    }
    
    // In first case, the s[i] is the true center of Palindrome substring
    std::string longestPalinAtPositioni1(std::string s, int index) {
        int j = 1;
        int length = 1;
        std::string result;
        std::string former, latter;
        result.push_back(s[index]);
        
        while (((index - j) >= 0) && ((index + j) <= s.length() - 1) && (s[index - j] == s[index + j])) {
            former = ""; former.push_back(s[index - j]);
            latter = ""; latter.push_back(s[index + j]);
            length = length + 2;
            j = j + 1;
            result = former + result + latter;
        }
        
        return result;
    }
    
    // In second case, the s[i] is the left center of Palindrome substring
    std::string longestPalinAtPositioni2(std::string s, int index) {
        int j = 0;
        int length = 0;
        std::string result = "";
        std::string former, latter;
        
        while ((s[index - j] == s[index + j + 1]) && ((index - j) >= 0) && ((index + j + 1) <= s.length() - 1)) {
            former = ""; former.push_back(s[index - j]);
            latter = ""; latter.push_back(s[index + j + 1]);
            length = length + 2;
            j = j + 1;
            result = former + result + latter;
        }
        return result;
    }
    
    
    std::string stringPreproc(std::string s) {
        size_t stringLength = s.length();
        
        for (size_t i = 0; i < stringLength + 1; i++) {
            s.insert(2*i, "#");
        }
        std::cout << s << std::endl;
        return s;
    }
    
    std::string longestPalindrome_improved(std::string s) {
        std::string result;
        int strLength = (int) s.length();
        int P[strLength];
        //unsigned int longest = 1;
        int position = 1;
        int center = 1;
        int boundary = 2;
        int tmp = 0;
        P[0] = 0;
        P[1] = 1;
        for (int i = 2; i < strLength; i++) {
            if (i > center + P[center]) {
                P[i] = 0;
                for (int j = 1; j < strLength - i; j++) {
                    if ((i - j >= 0) && (i + j < strLength) && (s[i - j] == s[i + j])) {
                        P[i] = P[i] + 1;
                    } else {
                        break;
                    }
                }
                boundary = i + P[i];
                center = i;
            } else {
                if (P[2*center - i] < P[center] - i + center) {
                    P[i] = P[2*center - i];
                } else {
                    P[i] = P[center] + center - i;
                    tmp = P[i];
                    //std::cout << P[i] << std::endl;
                    if (i > boundary) {
                        boundary = i;
                    }
                    for (int j = boundary - i + 1; j < strLength - i; j++) {
                        if ((i - j >= 0) && (i + j < strLength) && (s[i - j] == s[i + j])) {
                            P[i] = P[i] + 1;
                        } else {
                            break;
                        }
                    }
                    
                    if (P[i] > tmp) {
                        boundary = i + P[i];
                        center = i;
                    }
                }
            }
            //std::cout << P[i] << std::endl;
            if (P[i] > P[position]) {
                position = i;
            }
        }
        
        result = s.substr(position - P[position], 2 * P[position] + 1);
        int strLenResul = (int) result.length();
        for (int i = 0; i < (strLenResul + 1) / 2; i++) {
            result.erase(result.begin() + i);
        }
        std::cout << result << std::endl;
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::string s = "a";
    std::string result;
    Solution solution;
    result = solution.stringPreproc(s);
    result = solution.longestPalindrome_improved(result);
    
    return 0;
}
