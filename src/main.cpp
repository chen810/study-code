#include <iostream>
#include <string>
#include "leetcode_solution.h"
using namespace std;
int main() {
    vector<vector<int>> p{{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    cout << Solution::matrixScore(p)<<"\n";

}