#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<bool> rowSign(row,false);
        vector<bool> colSign(col,false);
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(matrix[i][j]==0){
                    rowSign[i] = true;
                    colSign[j] = true;
                }
            }
        }
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(rowSign[i]||colSign[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }

    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> res(row*col,0);
        int i=0,j=0,l=0;
        while(i+j<row+col-1){
            res[l++] = matrix[i][j];
            if((i+j)%2){
                if(i==row-1){
                    j += 1;
                }else if(j==0){
                    i += 1;
                }else{
                    i += 1;
                    j -= 1;
                }
            }else{
                if(j==col-1){
                    i += 1;
                }else if(i==0){
                    j += 1;
                }else{
                    i -= 1;
                    j += 1;
                }
            }
        }
        return res;
    }
};
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