// 拼接最大数
/* 给定长度分别为 m 和 n 的两个数组，其元素由 0-9 构成，表示两个自然数各位上的数字
 * 现在从这两个数组中选出 k (k <= m + n) 个数字拼接成一个新的数
 * 要求从同一个数组中取出的数字保持其在原数组中的相对顺序
 * 求满足该条件的最大数。结果返回一个表示该最大数的长度为 k 的数组
 * 说明: 请尽可能地优化你算法的时间和空间复杂度
 * */
// HARD 贪心 单调栈求最大子串
/* 将结果拆成2部分分别求,然后进行合并,取合并的最大值(分治)
 * 在求每一个最大时采用单调栈(单调栈)
 * 合并时进行字符串大小比较取较大的字符，保证最后是最大的(贪心)
 * */
class Solution {
public:
    //
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
        int m = nums1.size(), n = nums2.size(); // 两数组长度
        vector<int> maxSubsequence(k, 0);   // 最大队列结果
        int start = max(0, k - n), end = min(k, m); // 第一个子串的长度范围
        for (int i = start; i <= end; i++) {    // 分别取子串
            vector<int> subsequence1(MaxSubsequence(nums1, i)); // 第一中长度为i的子串
            vector<int> subsequence2(MaxSubsequence(nums2, k - i)); // 第二个中长度为k-i的子串
            vector<int> curMaxSubsequence(merge(subsequence1, subsequence2));   // 两子串合并为结果
            if (compare(curMaxSubsequence, 0, maxSubsequence, 0) > 0) { // 如果子串比上一个大则更新
                maxSubsequence.swap(curMaxSubsequence);
            }
        }
        return maxSubsequence;  // 返回最大子串
    }

    // 求长度为k的最大子串
    vector<int> MaxSubsequence(vector<int> &nums, int k) {
        int length = nums.size();   // 串长度
        vector<int> stack(k, 0);    // 单调栈
        int top = -1;   // 栈顶指针位置
        int remain = length - k;    // 可移除的数字数量
        for (int i = 0; i < length; i++) {  // 循环压入栈中
            int num = nums[i];  // 取出数字
            // 栈顶数组小于插入数字且还能移除则进行移除
            while (top >= 0 && stack[top] < num && remain > 0) {
                top--;
                remain--;
            }
            if (top < k - 1) {  // 若长度不足则压入
                stack[++top] = num;
            } else {    // 否则移除
                remain--;
            }
        }
        return stack;   // 返回最大子串
    }

    // 合并两数字串
    vector<int> merge(vector<int> &subsequence1, vector<int> &subsequence2) {
        int x = subsequence1.size(), y = subsequence2.size();   // 两子串长度
        if (x == 0) {   // 若其中一个数组串长度小于0则直接返回另一串
            return subsequence2;
        }
        if (y == 0) {
            return subsequence1;
        }
        int mergeLength = x + y;    // 总长度为两串长度和
        vector<int> merged(mergeLength);    // 合并结果串
        int index1 = 0, index2 = 0; // 两数字串指针
        for (int i = 0; i < mergeLength; i++) { // 合并
            // 取剩余部分较大的放在前面,若比较位相同则向后比较
            if (compare(subsequence1, index1, subsequence2, index2) > 0) {
                merged[i] = subsequence1[index1++];
            } else {
                merged[i] = subsequence2[index2++];
            }
        }
        return merged; // 返回合并结果
    }

    // 比较函数,(strcmp的比较方式)
    int compare(vector<int> &subsequence1, int index1, vector<int> &subsequence2, int index2) {
        int x = subsequence1.size(), y = subsequence2.size();   // 子串长度
        while (index1 < x && index2 < y) {  // 当两串均有剩余字符进行比较
            int difference = subsequence1[index1] - subsequence2[index2]; // 比较处的差值
            if (difference != 0) {  // 不相同返回差值
                return difference;
            }
            index1++;   // 同时后移
            index2++;   // 同时后移
        }
        return (x - index1) - (y - index2); // 两差必有一0,可直接返回长度比较
    }
};