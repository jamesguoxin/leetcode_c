//
//  main.cpp
//  addTwoNumbers
//
//  Created by Xin Guo on 10/10/14.
//  Copyright (c) 2014 JamesGuo. All rights reserved.
//

#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *sum = NULL;
        ListNode *last = NULL;
        ListNode *current_l1, *current_l2;
        int carry = 0;
        
        current_l1 = l1;
        current_l2 = l2;
        while ((current_l1 != NULL) || (current_l2 != NULL) || (carry > 0)) {
            int val_l1 = (current_l1 == NULL ? 0 : current_l1->val);
            int val_l2 = (current_l2 == NULL ? 0 : current_l2->val);
            
            int val_sum = (val_l1 + val_l2 + carry) % 10;
            ListNode *tmp = new ListNode(val_sum);
            carry = (val_l1 + val_l2 + carry) / 10;
            
            if (sum == NULL) {
                sum = tmp;
            }
            else {
                last->next = tmp;
            }
            
            last = tmp;
            
            if (current_l1 != NULL) {
                current_l1 = current_l1->next;
            }
            
            if (current_l2 != NULL) {
                current_l2 = current_l2->next;
            }
        }
        
        return sum;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode *a1 = new ListNode(2);
    ListNode *a2 = new ListNode(4);
    ListNode *a3 = new ListNode(3);
    
    ListNode *b1 = new ListNode(5);
    ListNode *b2 = new ListNode(6);
    ListNode *b3 = new ListNode(4);

    a1->next = a2; a2->next = a3;
    b1->next = b2; b2->next = b3;
    
    Solution s;
    
    ListNode *sum = NULL;
    
    sum = s.addTwoNumbers(a1, b1);
    
    while (sum != NULL) {
        std::cout << sum->val << std::endl;
        sum = sum->next;
    }
    return 0;
}
