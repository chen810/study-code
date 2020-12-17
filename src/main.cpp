#include "leetcode_solution.h"
#include "luogu_solution.h"
#include <iostream>

using namespace std;

int main() {
    vector<int> p{1, 2, 3, 4, 4, 4, 3, 3, 2, 1};
    Leetcode_solution::bucketSort(p);
    for (auto &i:p) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}