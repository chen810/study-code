// 415. 字符串相加
/*
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
提示：
    num1 和num2 的长度都小于 5100
    num1 和num2 都只包含数字 0-9
    num1 和num2 都不包含任何前导零
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1=="0"){
            return num2;
        }else if(num2=="0"){
            return num1;
        }
        int l1 = num1.size();
        int l2 = num2.size();
        int lr = max(l1,l2)+1;
        int flagOF = 0;
        string res(lr,'0');
        for(int i=0;i<lr;++i){
            if(i<l1){
                 res[lr-1-i] = num1[l1-1-i];
            }
            int temp = res[lr-1-i]+flagOF-'0';
            if(i<l2){
                temp += num2[l2-1-i]-'0';
                flagOF = temp/10;
                res[lr-1-i] = temp-flagOF*10+'0'; 
            }
            flagOF = temp/10;
            res[lr-1-i] = temp-flagOF*10+'0'; 
        }
        if(res[0]=='0'){
            return res.substr(1,lr);
        }
        return res;
    }
};
int main(){
    string a = "999998";
    string b = "3";
    Solution act;
    string c = act.addStrings(a,b);
    cout << c << endl;
    return 0;
}