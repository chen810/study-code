// ��ָ Offer 20. ��ʾ��ֵ���ַ���
/**
 * ��ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С����
 * ���磬�ַ���"+100"��"5e2"��"-123"��"3.1416"��"-1E-16"��"0123"����ʾ��ֵ
 * ��"12e"��"1a3.14"��"1.2.3"��"+-5"��"12e+5.4"������
 * */
#include <string>
using namespace std;

class Solution {
    int checkSheet[9][6]{
        {1 ,2 ,3 ,10,10, 0},    // stata 0:��ʼ����ȥ����ͷ�ո�
        {10,2 ,3 ,10,10,10},    // stata 1:ȡ�÷���
        {10,2 ,4 , 5, 9, 8},    // stata 2:ȡ������
        {10,4 ,10,10,10,10},    // stata 3:���������ֵ
        {10,4 ,10, 5, 9, 8},    // stata 4:���������ֵ
        {6 ,7 ,10,10,10,10},    // stata 5:��ѧ������
        {10,7 ,10,10,10,10},    // stata 6:ָ�������ŵĿ�ѧ������
        {10,7 ,10,10, 9, 8},    // stata 7:��������ָ��
        {10,10,10,10, 9, 8}     // stata 8:ĩβ�ո�
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