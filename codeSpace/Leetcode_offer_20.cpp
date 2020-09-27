// 剑指 Offer 20. 表示数值的字符串
/**
 * 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）
 * 例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"-1E-16"、"0123"都表示数值
 * 但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是
 * */
#include <string>
using namespace std;

class Solution {
    int checkSheet[9][6]{
        {1 ,2 ,3 ,10,10, 0},    // stata 0:初始化且去除开头空格
        {10,2 ,3 ,10,10,10},    // stata 1:取得符号
        {10,2 ,4 , 5, 9, 8},    // stata 2:取得数字
        {10,4 ,10,10,10,10},    // stata 3:点左侧无数值
        {10,4 ,10, 5, 9, 8},    // stata 4:点左侧有数值
        {6 ,7 ,10,10,10,10},    // stata 5:科学计数法
        {10,7 ,10,10,10,10},    // stata 6:指数带符号的科学计数法
        {10,7 ,10,10, 9, 8},    // stata 7:计数法的指数
        {10,10,10,10, 9, 8}     // stata 8:末尾空格
        // stata 9:finish
        // stata 10:error
    };
public:
    bool isNumber(string s) {
        int flag = 0;
        s.push_back('#');
        for(auto i:s){
            switch (i)
            {
            case '+':
            case '-':
                flag = checkSheet[flag][0];
                break;
            case '.':
                flag = checkSheet[flag][2];
                break;
            case '#':
                flag = checkSheet[flag][4];
                break;
            case 'E':
            case 'e':
                flag = checkSheet[flag][3];
                break;
            case ' ':
                flag = checkSheet[flag][5];
                break;
            default:
                if(i>='0'&&i<='9'){
                    flag = checkSheet[flag][1];
                }else{
                    flag = 10;
                }
                break;
            }
            // cout <<flag <<endl;
            if(flag == 10){
                return false;
            }
        }
        return flag==9;
    }
};