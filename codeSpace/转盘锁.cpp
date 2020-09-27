/** ����һ�������ĸ�Բ�β��ֵ�ת����
 * ÿ�����ֶ���10�����֣� '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
 * ÿ�����ֿ���������ת������� '9' ��Ϊ  '0'��'0' ��Ϊ '9' 
 * ÿ����ת��ֻ����תһ�����ֵ�һλ����
 * ���ĳ�ʼ����Ϊ '0000' ��һ�������ĸ����ֵ����ֵ��ַ���
 * �б� deadends ������һ����������
 * һ�����ֵ����ֺ��б�����κ�һ��Ԫ����ͬ����������ᱻ�����������޷��ٱ���ת
 * �ַ��� target ������Խ��������֣�����Ҫ������С����ת����
 * ���������β��ܽ��������� -1
 * */
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string clockerOp(string clocker, int index, bool dir){
        int temp = clocker[index] - '0';
        temp += dir?1:-1;
        if(temp>9){
            temp -= 10;
        }else if(temp<0){
            temp += 10;
        }
        clocker[index] = temp + '0';
        return clocker;
    }
    int openLock(vector<string>& deadends, string target) {
        queue<string> temp; // ��ʱ����
        unordered_set<string> visited;  // ��¼�Ѿ����ʵ�����
        unordered_set<string> deads;    // ��¼�޷���������
        temp.push("0000");  // ��ʼ������
        visited.insert("0000"); // �ѷ���"0000"
        for(auto i:deadends){   // ��set��¼�޷����ʵ�����
            deads.insert(i);
        }
        int step = 0;   // ��¼����
        while(!temp.empty()){
            int l = temp.size();    // ѭ����������
            for(int i=0;i<l;++i){
                string t = temp.front();    // ȡ������
                temp.pop();
                if(deads.find(t)!=deads.end()){ // �ж��Ƿ�������޷������б�
                    continue;
                }
                if(t == target){
                    return step;
                }
                for(int j=0;j<4;++j){
                    string t1 =  clockerOp(t,j,true);
                    string t2 = clockerOp(t,j,false);
                    if(visited.find(t1)==visited.end()){
                        temp.push(t1);
                        visited.insert(t1);
                    }
                    if(visited.find(t2)==visited.end()){
                        temp.push(t2);
                        visited.insert(t2);
                    }
                }
                step++;
            }
        }
        return -1;
    }
    
};