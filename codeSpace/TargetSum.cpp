// Ŀ���
/** ����һ���Ǹ��������飬a1, a2, ..., an, ��һ��Ŀ������S������������������ + �� -
 * ���������е�����һ���������㶼���Դ� + �� -��ѡ��һ�����������ǰ��
 * ���ؿ���ʹ���������ΪĿ���� S ��������ӷ��ŵķ�����
 * */

#include <vector>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int (*dp)[2001] = new int[nums.size()][2001]();
        dp[0][nums[0]+1000] = 1;
        dp[0][-nums[0]+1000] += 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int sum = -1000; sum <= 1000; sum++) {
                if (dp[i - 1][sum + 1000] > 0) {
                    dp[i][sum + nums[i] + 1000] += dp[i - 1][sum + 1000];
                    dp[i][sum - nums[i] + 1000] += dp[i - 1][sum + 1000];
                }
            }
        }
        return S > 1000 ? 0 : dp[nums.size() - 1][S + 1000];
    }
};