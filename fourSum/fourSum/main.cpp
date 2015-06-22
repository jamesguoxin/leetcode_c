//
//  main.cpp
//  fourSum
//
//  Created by Xin Guo on 17/06/15.
//  Copyright (c) 2015 JamesGuo. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4) return res;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 3; ) {
            for (int j = i + 1; j < nums.size() - 2; ) {
                int value = target - nums[i] - nums[j];
                int k = j + 1;
                int l = int(nums.size()) - 1;
                
                while (k < l) {
                    if (nums[k] + nums[l] < value) {
                        k++;
                        while (k < l && nums[k] == nums[k-1]) k++;
                    } else if (nums[k] + nums[l] > value) {
                        l--;
                        while (k < l && nums[l] == nums[l+1]) l--;
                    } else {
                        vector<int> tmp {nums[i], nums[j], nums[k], nums[l]};
                        res.push_back(tmp);
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k-1]) k++;
                        while (k < l && nums[l] == nums[l+1]) l--;
                    }
                }
                j++;
                while (j < nums.size() - 2 && nums[j] == nums[j - 1] ) j++;
            }
            i++;
            while (i < nums.size() - 3 && nums[i] == nums[i - 1]) i++;
        }
        
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution check;
    vector<int> nums {0, 4, -5, 2, -2, 4, 2, -1, 4};
    int target = 12;
    vector<vector<int>> res = check.fourSum(nums, target);
    std::cout << "Hello, World!\n";
    return 0;
}
