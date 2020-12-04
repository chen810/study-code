/*字符串中取最长回文字串的算法：
 *使用马拉车算法 Manacher‘s Algorithm
 * 为避免奇偶字串影响，在字串间隔中插入一个其他字符这里取#，首尾结束符分别为$&
 * 取一个数组t(这里使用vector代替了数组),记录以每个位置为中心的回文字串半径长度
 * 结果将长度除以2为插入前字串的下标
 * 复杂的为O(n)----> Manacher_NB
 * */
#include <iostream>
#include <vector>

using namespace std;

static string manacher(const string &s) {
    // 对字串进行插入构造，形如$#a#...#z#&
    string p("$");
    for (auto i:s) {
        p.push_back('#');
        p.push_back(i);
    }
    p.push_back('#');
    p.push_back('&');

    // 取int容器记录对应位置最大回文子串半径，首先置0
    int length_p = static_cast<int>(p.size());
    vector<int> t(length_p, 0);
    // c,r为控制参数, r为当前回文串最右位置，c为r取最右位置时的中心
    int c = 0, r = 0;
    // 从第一个#开始遍历到最后一个#
    for (int l = 1; l < length_p - 1; ++l) {
        // 获取关于c的镜像下标
        int l_m = 2 * c - l;
        // 最右回文字串在所在下标的右面，防止目前回文字串的最右超过原有最右，取保守值
        if (r > l) {
            t[l] = r - l < t[l_m] ? r - l : t[l_m];
        }
        // 对当前下标字串采取双向扩张，直到不能扩张
        while (p[l + 1 + t[l]] == p[l - 1 - t[l]]) {
            ++t[l];
        }
        // 判断目前的最右边界是否大于原来最右边界，大于则同时更新c和r
        if (l + t[l] > r) {
            r = l + t[l];
            c = l;
        }
    }
    // 判断出最长字串中心以及最长时的半径
    r = 0;
    for (int index = 0; index < length_p; ++index) {
        cout << t[index] << " ";
        if (r < t[index]) {
            c = index;
            r = t[c];
        }
    }
    // 根据c,r取出答案所需要的回文子串并且作为返回值返回
    string res;
    for (int k = (c - r) / 2; k < (c + r) / 2; ++k) {
        res.push_back(s[k]);
    }
    return res;
}