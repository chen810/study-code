// 完全平方数
/* 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）
 * 使得它们的和等于 n。你需要让组成和的完全平方数的个数最少
 * */
#include <iostream>
#include <cmath>

class Solution {
public:
    int numSquares(int n) {
        int *temp = new int[n + 1]();
        for (int i = 1; i <= n; ++i) {
            int sqrt4i = sqrt(i);
            if (sqrt4i * sqrt4i == i) {
                temp[i] = 1;
                continue;
            }
            int left = 1;
            int leftDouble = 1;
            int s = temp[leftDouble] + temp[i - leftDouble];
            while (2 * leftDouble <= i) {
                int tt = temp[leftDouble] + temp[i - leftDouble];
                s = s > tt ? tt : s;
                left++;
                leftDouble = left * left;
            }
            temp[i] = s;
        }
        return temp[n];
    }
};