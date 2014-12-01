//
//  main.cpp
//  zigzag
//
//  Created by Xin Guo on 30/10/14.
//  Copyright (c) 2014 JamesGuo. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int nRows) {
        if (nRows == 1)
        {
            return s;
        }
        else
        {
            std::vector<std::string> stringRows(nRows, "");
            int index = 0;
            int flag = 1;
            for (size_t i = 0; i < s.length(); i++) {
                stringRows[index].push_back(s[i]);
                if (index == nRows - 1 || index == 0) {
                    flag = (flag + 1) % 2;
                }
                if (flag == 0) {
                    index = index + 1;
                } else {
                    index = index - 1;
                }
                
            }
            std::string result = "";
            for (size_t i = 0; i < nRows; i++) {
                result = result + stringRows[i];
            }
            return result;
        }
    }
};

int main(int argc, const char * argv[]) {
    std::string s = "PAYPALISHIRING";
    Solution solution;
    std::string result;
    result = solution.convert(s, 3);
    std::cout << result << std::endl;
    return 0;
}
