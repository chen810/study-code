// 分割数组为连续子序列
/* 给你一个按升序排序的整数数组 num（可能包含重复数字）
 * 请你将它们分割成一个或多个子序列，其中每个子序列都由连续整数组成且长度至少为 3
 * 如果可以完成上述分割，则返回 true ；否则，返回 false
 * */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;


class Solution {
public:
    // 哈希表+小根堆,尽可能保证较短的串能够被延长
    bool isPossible(vector<int>& nums) {
        // 哈希表键为int-->子序列的末尾数字,值为小根堆-->存储以同末尾的序列长度
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>>  mp;
        for (auto &x : nums) {  // 逐个取出
            if (mp.find(x) == mp.end()) {   // 若无以x结尾则创建
                mp[x] = priority_queue<int, vector<int>, greater<int>>();
            }
            if (mp.find(x - 1) != mp.end()) {   // 若有以x-1结尾则进行续接
                int minSize = mp[x - 1].top();  // 最短长度
                mp[x - 1].pop();    // 清除最短
                if (mp[x - 1].empty()) {    // 若无以x-1结尾则清空
                    mp.erase(x - 1);
                }
                mp[x].push(minSize + 1);    // 在x结尾的表中加入新长度
            }
            else {
                mp[x].push(1);  // 创建新的子序列,长度为1,结尾为x
            }
        }
        for (auto& t : mp) {    // 对于每一串长度都有>=3,只需检查同结尾的最短那串长度
            if (t.second.top() < 3) {
                return false;
            }
        }
        return true;
    }
    // 贪心,另建新子序列一定不如续接更有可能拆分成功
    bool isPossible1(vector<int>& nums) {
        map<int, int> pail; // 统计字符数量
        map<int, int> tail; // 以下标结尾子串数量
        for (auto& n : nums) {  // 计数
            pail[n]++;
        }
        for (auto& n : nums) {  // 遍历取出
            int count = pail[n];    // 取出字符的数量
            if (count > 0) {    // 当>0时才能填入
                int prevalue = tail[n - 1]; // 以n-1结尾子串的数量
                if (prevalue > 0) { // 若存在n-1结尾则不进行创建,选择续接
                    pail[n] = count - 1;    // 字符-1
                    tail[n - 1] = prevalue -1;  // 以n-1结尾子串数量-1
                    tail[n] += 1;   // 以n结尾子串数量+1
                }
                else {
                    int a1 = pail[n + 1];   // 大1的数
                    int a2 = pail[n + 2];   // 大2的数
                    if (a1 > 0 && a2 > 0) { // 仅当均有的时候进行创建
                        pail[n] = count - 1;    // n的数量-1
                        pail[n + 1] = a1 - 1;   // n+1的数量-1
                        pail[n + 2] = a2 - 1;   // n+2的数量-1
                        tail[n + 2] += 1;   // 以n+2结尾的数量+1
                    }
                    else {
                        return false;   // 不能拼接返回false
                    }
                }
            }
        }
        return true;    // 拼接无错误返回true
    }
};
int main() {
    vector<int> p{ 1,2,3,3,3,4,5 };
    Solution res;
    cout << res.isPossible(p) << endl;
    return 0;
}

