// 最短回文串
/*
 * 给定一个字符串 s
 * 你可以通过在字符串前面添加字符将其转换为回文串
 * 找到并返回可以用这种方式转换的最短回文串
*/
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // KMP解法
    string shortestPalindrome(string s) {
        vector<int> next(s.size(),-1);  // KMP的next数组,原字符串作为模式串
        for(int i=1;i<s.size();++i){
            int j = next[i-1];
            while(j!=-1&&s[i]!=s[j]){
                j = next[j] + 1;
            }
            if(s[i]==s[j]){
                next[i] = j + 1;
            }
        }
        int best = -1;  // 使用字符串的原字符串作为查询字符串进行匹配
        for(int i=s.size()-1;i>=0;--i){
            while(best!=-1&&s[i]!=s[best]){
                best = next[best];
            }
            if(s[best]==s[i]){
                best++;
            }
        }   // 当查询字符串无剩余时,已经匹配的即为回文前后缀
        string add = (best==s.size()-1?"":s.substr(best+1,s.size()));   // 取剩余部分进行逆置
        reverse(add.begin(),add.end());
        return add+s;   // 剩余部分逆置+原字符串
    }
};