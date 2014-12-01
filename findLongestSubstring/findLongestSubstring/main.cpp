//
//  main.cpp
//  findLongestSubstring
//
//  Created by Xin Guo on 06/10/14.
//  Copyright (c) 2014 JamesGuo. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::map<char, int> hashTable;
        int tmpLongest = 0;
        int currentLongest = 0;
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            if (hashTable.find(s[i]) == hashTable.end()) {
                hashTable[s[i]] = i;
            }
            //std::cout << s[i] << std::endl;
            //std::cout << hashTable[s[i]] << std::endl;
            if (((hashTable[s[i]] < i) && (hashTable[s[i]] >= j)) || (i == s.length() - 1)) {
                if ((i == s.length() - 1) && (hashTable[s[i]] == i))
                    tmpLongest = i - j + 1;
                else
                    tmpLongest = i - j;
                for (int k = j; k < hashTable[s[i]]; k++) {
                    hashTable.erase(s[k]);
                }
                j = hashTable[s[i]] + 1;
                hashTable[s[i]] = i;
                
                if (tmpLongest > currentLongest) {
                    currentLongest = tmpLongest;
                }
            }
        }
        
        return currentLongest;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::string s = "vfauaosnlnvacsvpiumoiawcqxswkqwgxyazntnaikameybnuqb";
    int lengthOfLongest;
    Solution solution;
    lengthOfLongest = solution.lengthOfLongestSubstring(s);
    
    std::cout << lengthOfLongest << std::endl;
    return 0;
}
