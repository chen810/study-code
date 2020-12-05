// 任务调度器
/* 给你一个用字符数组 tasks 表示的 CPU 需要执行的任务列表
 * 其中每个字母表示一种不同种类的任务
 * 任务可以以任意顺序执行，并且每个任务都可以在 1 个单位时间内执行完
 * 在任何一个单位时间，CPU 可以完成一个任务，或者处于待命状态
 * 然而，两个 相同种类 的任务之间必须有长度为整数 n 的冷却时间
 * 因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态
 * 你需要计算完成所有任务所需要的 最短时间
 * */

#include <vector>
#include <unordered_map>

class Solution {
public:
    // 我们应当选择剩余执行次数最多的那个可以执行的任务，将每种任务的剩余执行次数尽可能平均
    int leastInterval(vector<char> &tasks, int n) {
        // 计数
        unordered_map<char, int> freq;
        for (char ch: tasks) {
            ++freq[ch];
        }
        // 任务总数
        int m = freq.size();
        vector<int> nextValid, rest; // 下一次可填入的时间,剩余个数
        for (auto[_, v]: freq) {
            nextValid.push_back(1);
            rest.push_back(v);
        }
        // 时间线起始为0
        int time = 0;
        for (int i = 0; i < tasks.size(); ++i) {
            ++time; // 对于每次填入,时间线+1
            int minNextValid = INT_MAX; // 最近的下一次填入位置,初始化最大
            for (int j = 0; j < m; ++j) {   // 对于每种事件
                if (rest[j]) {  // 有剩余则判断下一次填入位置
                    minNextValid = min(minNextValid, nextValid[j]);
                }
            }
            // 时间点移动到下一次填入后
            time = max(time, minNextValid);
            // 寻找将要插入的事件
            int best = -1;
            for (int j = 0; j < m; ++j) {
                if (rest[j] && nextValid[j] <= time) {  // 有剩余 且 不大于已判断出的最近距离
                    if (best == -1 || rest[j] > rest[best]) {   // 优先插入更多的事件
                        best = j;
                    }
                }
            }
            // 插入的事件下次可以再次插入的时间点,计数-1
            nextValid[best] = time + n + 1;
            --rest[best];
        }
        return time; // 插入完毕的时间点
    }
    // 流水线,设事件种类为X,间隔为n,最多的事件有max种,数量为M
    // 当X<n+1时每种事件仅能出现1次,故总时间受最多的事件限制,time = max + (n+1)*M
    // 当X>=n+1时,每种顺序按顺序摆一定不会受限制,time = tasks.size()
    // 两种混合即为max(max + (n+1)*M,tasks.size())
    int leastInterval1(vector<char>& tasks, int n) {
        // 计数
        unordered_map<char, int> freq;
        for (char ch: tasks) {
            ++freq[ch];
        }
        // 最多的执行次数
        int maxExec = max_element(freq.begin(), freq.end(), [](const auto& u, const auto& v) {
            return u.second < v.second;
        })->second;
        // 具有最多执行次数的任务数量
        int maxCount = accumulate(freq.begin(), freq.end(), 0, [=](int acc, const auto& u) {
            return acc + (u.second == maxExec);
        });
        // 公式计算
        return max((maxExec - 1) * (n + 1) + maxCount, static_cast<int>(tasks.size()));
    }
};
