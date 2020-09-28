// 预测赢家
/**
 * 给定一个表示分数的非负整数数组
 * 玩家 1 从数组任意一端拿取一个分数，随后玩家 2 继续从剩余数组任意一端拿取分数
 * 每次一个玩家只能拿取一个分数，分数被拿取之后不再可取
 * 直到没有剩余分数可取时游戏结束
 * 最终获得分数总和最多的玩家获胜
 * 给定一个表示分数的数组，预测玩家1是否会成为赢家
 * 你可以假设每个玩家的玩法都会使他的分数最大化
 * */
#include <vector>

using namespace std;
// 动态规划
/**
 * 建立数组,dp[i][j]表示i,j之间所产生的最大的差值
 * 动规表达式: dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
*/
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int length = nums.size();
        auto dp = vector<int>(length);
        for (int i = 0; i < length; i++) {
            dp[i] = nums[i];
        }
        for (int i = length - 2; i >= 0; i--) {
            for (int j = i + 1; j < length; j++) {
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }
        return dp[length - 1] >= 0;
    }
};