// 打开转盘锁
/* 你有一个带有四个圆形拨轮的转盘锁
 * 每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
 * 每个拨轮可以自由旋转：例如把 '9' 变为  '0'，'0' 变为 '9' 
 * 每次旋转都只能旋转一个拨轮的一位数字
 * 锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串
 * 列表 deadends 包含了一组死亡数字
 * 一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转
 * 字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数
 * 如果无论如何不能解锁，返回 -1
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
        queue<string> temp; // 临时队列
        unordered_set<string> visited;  // 记录已经访问的密码
        unordered_set<string> deads;    // 记录无法访问密码
        temp.push("0000");  // 初始化队列
        visited.insert("0000"); // 已访问"0000"
        for(auto i:deadends){   // 用set记录无法访问的密码
            deads.insert(i);
        }
        int step = 0;   // 记录步数
        while(!temp.empty()){
            int l = temp.size();    // 循环遍历队列
            for(int i=0;i<l;++i){
                string t = temp.front();    // 取出队首
                temp.pop();
                if(deads.find(t)!=deads.end()){ // 判断是否存在于无法访问列表
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