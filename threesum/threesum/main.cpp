//
//  main.cpp
//  threesum
//
//  Created by Xin Guo on 04/06/15.
//  Copyright (c) 2015 JamesGuo. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ) {
            if (nums[i] > 0) {
                i++;
                continue;
            }
            int start = i + 1;
            int end = int(nums.size() - 1);
            
            while (start < end) {
                if (nums[i] + nums[start] + nums[end] == 0) {
                    vector<int> tmp {nums[i], nums[start], nums[end]};
                    result.push_back(tmp);
                    start++;
                    end--;
                } else if (nums[i] + nums[start] + nums[end] < 0) {
                    start++;
                } else if (nums[i] + nums[start] + nums[end] > 0) {
                    end--;
                }
                
                while (start < end && nums[start] == nums[start - 1]) start++;
                while (start < end && nums[end] == nums[end + 1]) end--;
            }
            
            i++;
            while(i < nums.size() && nums[i] == nums[i - 1]) i++;
        }
        
        return result;
        
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums {1, 1, 1};
    Solution solu;
    vector<vector<int>> result;
    result = solu.threeSum(nums);
    return 0;
}
