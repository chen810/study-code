// 矩阵置零
/* 给定一个 m x n 的矩阵，如果一个元素为 0
 * 则将其所在行和列的所有元素都设为 0
 * 请使用原地算法
 * */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<bool> rowSign(row, false);
        vector<bool> colSign(col, false);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == 0) {
                    rowSign[i] = true;
                    colSign[j] = true;
                }
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (rowSign[i] || colSign[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};