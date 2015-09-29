//
//  main.cpp
//  postfix
//
//  Created by Xin Guo on 23/06/15.
//  Copyright (c) 2015 JamesGuo. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class postfix {
public:
    int evaluation(string s) {
        int value, nums1, nums2, num;
        string postS = getPostString(s);
        int len = postS.length();
        stack<int> nums;
        value = 0;
        
        for (int i = 0; i < len; i++) {
            switch (postS[i]) {
                case '+':
                    nums1 = nums.top();
                    nums.pop();
                    nums2 = nums.top();
                    nums.pop();
                    value = nums1 + nums2;
                    nums.push(value);
                    break;
                case '-':
                    nums1 = nums.top();
                    nums.pop();
                    nums2 = nums.top();
                    nums.pop();
                    value = nums2 - nums1;
                    nums.push(value);
                    break;
                case '*':
                    nums1 = nums.top();
                    nums.pop();
                    nums2 = nums.top();
                    nums.pop();
                    value = nums1 * nums2;
                    nums.push(value);
                    break;
                case '/':
                    nums1 = nums.top();
                    nums.pop();
                    nums2 = nums.top();
                    nums.pop();
                    value = nums2 / nums1;
                    nums.push(value);
                    break;
                default:
                    num = 0;
                    while (postS[i] != '#') {
                        num = 10 * num + int(postS[i] - '0');
                        i++;
                    }
                    nums.push(num);
            }
        }
        
        return value;
    }
    
    string getPostString(string s) {
        string postS = "";
        stack<char> operators;
        int len = s.length();
        
        for (int i = 0; i < len; i++) {
            if (s[i] == ' ') {
                continue;
            } else if (isOperand(s[i])) {
                while (isOperand(s[i])) {
                    postS += s[i];
                    i++;
                }
                i--;
                postS += '#';
            } else if (isOperator(s[i])) {
                while (!operators.empty() && operators.top() != '(' && higherOperator(operators.top(), s[i])) {
                    postS += operators.top();
                    operators.pop();
                }
                operators.push(s[i]);
                
            } else if (s[i] == '(') {
                operators.push(s[i]);
            } else if (s[i] == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    postS += operators.top();
                    operators.pop();
                }
                operators.pop();
            }
        }
        
        while (!operators.empty()) {
            postS += operators.top();
            operators.pop();
        }
        
        return postS;
    }
    
    bool isOperand(char c) {
        if (c <= '9' && c >= '0') {
            return true;
        } else {
            return false;
        }
    }
    
    bool isOperator(char c) {
        if (c == '+') return true;
        if (c == '-') return true;
        if (c == '*') return true;
        if (c == '/') return true;
        return false;
    }
    
    bool higherOperator(char o1, char o2) {
        int weight1 = opWeight(o1);
        int weight2 = opWeight(o2);
        
        if (weight1 >= weight2) {
            return true;
        } else {
            return false;
        }
    }
    
    int opWeight(char o) {
        int weight = -1;
        switch (o) {
            case '-':
            case '+':
                weight = 1;
                break;
            case '/':
            case '*':
                weight = 2;
                break;
            default:
                weight = 0;
                break;
        }
        
        return weight;
    }
};


int main(int argc, const char * argv[]) {
    string s = "  32 * (98 + 78) * 12 - 12 / 6  ";
    postfix p;
    string post = p.getPostString(s);
    int result = p.evaluation(s);
    std::cout << post << std::endl;
    std::cout << result << std::endl;
    return 0;
}
