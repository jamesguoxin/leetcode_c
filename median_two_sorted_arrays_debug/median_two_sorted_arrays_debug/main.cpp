//
//  main.cpp
//  median_two_sorted_arrays_debug
//
//  Created by Xin Guo on 03/10/14.
//  Copyright (c) 2014 JamesGuo. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <algorithm>
int findKth(int A[], int m, int B[], int n, int k) {
    if (m > n)
        return findKth(B, n, A, m, k);
    if (m == 0)
        return B[k - 1];
    if (k == 1)
        return std::min<int>(A[0], B[0]);
    
    int pa = std::min<int>(k / 2, m);
    int pb = k - pa;
    
    if (A[pa - 1] < B[pb - 1])
        return findKth(A + pa, m - pa, B, n, k - pa);
    else if (A[pa - 1] > B[pb - 1])
        return findKth(A, m, B + pb, n - pb, k - pb);
    else
        return A[pa - 1];
};

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((m + n) % 2 == 1)
            return (double)findKth(A, m, B, n, (m + n) / 2 + 1);
        else
            return (findKth(A, m, B, n, (m + n) / 2) +
                    findKth(A, m, B, n, (m + n) / 2 + 1)) * 0.5;
    }
};

int main() {
    int a[] = {2, 6, 19, 21, 34, 45};
    int b[] = {1, 23, 24, 67, 89};
    double result;
    Solution s;
    
    result = s.findMedianSortedArrays(a, 6, b, 5);
    
    printf("%f\n", result);

    return 0;
}
