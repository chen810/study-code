// ��̻��Ĵ�
/**
 * ����һ���ַ��� s
 * �����ͨ�����ַ���ǰ������ַ�����ת��Ϊ���Ĵ�
 * �ҵ������ؿ��������ַ�ʽת������̻��Ĵ�
*/
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // KMP�ⷨ
    string shortestPalindrome(string s) {
        vector<int> next(s.size(),-1);  // KMP��next����,ԭ�ַ�����Ϊģʽ��
        for(int i=1;i<s.size();++i){
            int j = next[i-1];
            while(j!=-1&&s[i]!=s[j]){
                j = next[j] + 1;
            }
            if(s[i]==s[j]){
                next[i] = j + 1;
            }
        }
        int best = -1;  // ʹ���ַ�����ԭ�ַ�����Ϊ��ѯ�ַ�������ƥ��
        for(int i=s.size()-1;i>=0;--i){
            while(best!=-1&&s[i]!=s[best]){
                best = next[best];
            }
            if(s[best]==s[i]){
                best++;
            }
        }   // ����ѯ�ַ�����ʣ��ʱ,�Ѿ�ƥ��ļ�Ϊ����ǰ��׺
        string add = (best==s.size()-1?"":s.substr(best+1,s.size()));   // ȡʣ�ಿ�ֽ�������
        reverse(add.begin(),add.end());
        return add+s;   // ʣ�ಿ������+ԭ�ַ���
    }
};