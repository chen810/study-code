#include <iostream>
#include <string>
#include "leetcode_solution.h"
using namespace std;
int main() {
    vector<vector<int>> p{{5,7},{1,8},{0,0},{2,3},{4,5},{0,6},{5,10},{7,10}};
    cout << Solution::videoStitching(p,5);
}