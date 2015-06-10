//
//  main.cpp
//  kthlargest
//
//  Created by Xin Guo on 27/05/15.
//  Copyright (c) 2015 JamesGuo. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 1) return nums[0];
        int rand_position = rand() % int(nums.size());
        int sorted_position = partition(nums, 0, int(nums.size() - 1), rand_position);
        
        if (sorted_position == k - 1) return nums[sorted_position];
        else if (sorted_position > k - 1) {
            return kthLargest(nums, 0, sorted_position - 1, k);
        } else {
            return kthLargest(nums, sorted_position + 1, int(nums.size() - 1), k);
        }
        
    }
    
    int partition(vector<int>& nums, int begin, int end, int position) {
        std::iter_swap(nums.begin() + end, nums.begin() + position);
        int current_position = begin;
        int value = nums[end];
        
        for (int index = begin; index <= end; index++) {
            if (nums[index] > value) {
                std::iter_swap(nums.begin() + current_position, nums.begin() + index);
                current_position++;
            }
        }
        std::iter_swap(nums.begin() + current_position, nums.begin() + end);
        return current_position;
    }
    
    int kthLargest(vector<int>& nums, int l, int r, int k) {
        int sorted_position = partition(nums, l, r, l);
        
        if (sorted_position == k - 1) return nums[sorted_position];
        else if (sorted_position > k - 1) {
            return kthLargest(nums, l, sorted_position - 1, k);
        } else {
            return kthLargest(nums, sorted_position + 1, r, k);
        }
    }
};

int main(int argc, const char * argv[]) {
    int k = 2;
    vector<int> test = {2, 1, 15};
    Solution kthlargest;
    int result = kthlargest.findKthLargest(test, k);
    std::cout << "The result is " << result << std::endl;
    return 0;
}
