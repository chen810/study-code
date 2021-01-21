#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int l = k%n;
        localFlip(nums, 0, n-1-l);
        localFlip(nums, n-l, n-1);
        localFlip(nums, 0, n-1);
    }
    void localFlip(vector<int>& nums, int st, int en){
        while(st<en){
            int p = nums[st];
            nums[st] = nums[en];
            nums[en] = p;
            st++;
            en--;
        }
    }
};