// Ԥ��Ӯ��
/**
 * ����һ����ʾ�����ķǸ���������
 * ��� 1 ����������һ����ȡһ�������������� 2 ������ʣ����������һ����ȡ����
 * ÿ��һ�����ֻ����ȡһ����������������ȡ֮���ٿ�ȡ
 * ֱ��û��ʣ�������ȡʱ��Ϸ����
 * ���ջ�÷����ܺ�������һ�ʤ
 * ����һ����ʾ���������飬Ԥ�����1�Ƿ���ΪӮ��
 * ����Լ���ÿ����ҵ��淨����ʹ���ķ������
 * */
#include <vector>

using namespace std;
// ��̬�滮
/**
 * ��������,dp[i][j]��ʾi,j֮�������������Ĳ�ֵ
 * ������ʽ: dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
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