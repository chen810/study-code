// 对角线遍历
#include <iostream>
#include <vector>

using namespace std;

/* 给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素
 * 如:vector<vector<int>> p{{1,2,3},{4,5,6},{7,8,9}};
 * 输出为:{1,2,4,7,5,3,6,8,9}
 * */
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> res(row * col, 0);
        int i = 0, j = 0, l = 0;
        while (i + j < row + col - 1) {
            res[l++] = matrix[i][j];
            if ((i + j) % 2) {
                if (i == row - 1) {
                    j += 1;
                } else if (j == 0) {
                    i += 1;
                } else {
                    i += 1;
                    j -= 1;
                }
            } else {
                if (j == col - 1) {
                    i += 1;
                } else if (i == 0) {
                    j += 1;
                } else {
                    i -= 1;
                    j += 1;
                }
            }
        }
        return res;
    }
};
/*
int main(){
    vector<vector<int>> p{
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    Solution s;
    auto res = s.findDiagonalOrder(p);
    for(auto i:res){
        cout <<i << endl;
    }
}
*/