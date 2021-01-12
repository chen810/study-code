#include "leetcode_solution.h"
#include "luogu_solution.h"
#include <iostream>

using namespace std;

int main() {
    vector<int> nums{1,1,1,1,2,2,2,2};
    map<int,int> nn;
    int count = 4;
    vector<int> dp(count+1,INT_MAX-1);
    dp[0] = 0;
    for(int num : nums) {
        for (int j = count; j > 0; --j) {
            if (j >= num) {
                dp[j] = min(dp[j], dp[j - num] + 1);
            }
        }
    }
        cout << dp[count] << endl;
    return 0;
}