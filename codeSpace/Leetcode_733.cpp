// 733.图像渲染
/*
 * 有一幅以二维整数数组表示的图画，每一个整数表示该图画的像素值大小，数值在 0 到 65535 之间
 * 给你一个坐标 (sr, sc) 表示图像渲染开始的像素值（行 ，列）和一个新的颜色值 newColor，让你重新上色这幅图像
 * 为了完成上色工作，从初始坐标开始，记录初始坐标的上下左右四个方向上像素值与初始坐标相同的相连像素点
 * 接着再记录这四个方向上符合条件的像素点与他们对应四个方向上像素值与初始坐标相同的相连像素点
 * 重复该过程。将所有有记录的像素点的颜色值改为新的颜色值
 * 最后返回经过上色渲染后的图像
 * */
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int row = image.size(); 
        int col = image[0].size();  // 记录图像大小
        int rawColor = image[sr][sc];   // 记录初始颜色
        queue<vector<int>> temp;    // 搜索未染色区域
        temp.push({sr,sc}); // 加入起始点
        while(!temp.empty()){   // 重复判断,直到不存在未染色区域
            int i = temp.front()[0];    // 取得下一个未染色块横坐标
            int j = temp.front()[1];    // 取得下一个未染色块纵坐标
            image[i][j] = newColor; // 染色
            temp.pop(); // 删除染色完成点
            if(i-1>=0&&image[i-1][j]==rawColor&&image[i-1][j]!=newColor){    // 加入四个方向的点,条件:区域内,与起始点连通,未染色
                temp.push({i-1,j});
            }
            if(i+1<row&&image[i+1][j]==rawColor&&image[i+1][j]!=newColor){
                temp.push({i+1,j});
            }
            if(j-1>=0&&image[i][j-1]==rawColor&&image[i][j-1]!=newColor){
                temp.push({i,j-1});
            }
            if(j+1<col&&image[i][j+1]==rawColor&&image[i][j+1]!=newColor){
                temp.push({i,j+1});
            }
        }
        return image;
    }
};