//
//  main.cpp
//  majority
//
//  Created by Xin Guo on 08/07/15.
//  Copyright (c) 2015 JamesGuo. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a, b, cnt1, cnt2;
        a = 0;
        b = 1;
        cnt1 = 0;
        cnt2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt1 == 0 || nums[i] == a) {
                a = nums[i];
                cnt1++;
            } else if (cnt2 == 0 || nums[i] == b) {
                b = nums[i];
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        
        cnt1 = 0;
        cnt2 = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == a) cnt1++;
            if (nums[i] == b) cnt2++;
        }
        
        vector<int> result;
        
        if (cnt1 > nums.size() / 3) result.push_back(a);
        if (cnt2 > nums.size() / 3 && a != b) result.push_back(b);
        
        return result;
        
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums {1, 2};
    Solution s;
    vector<int> result;
    result = s.majorityElement(nums);
    std::cout << "Hello, World!\n";
    return 0;
}
