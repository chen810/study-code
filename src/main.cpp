#include <iostream>
#include <string>
#include "leetcode_solution.h"
using namespace std;
int main() {
    vector<string> p{"abcd","bcd"};
    auto q = Solution::ommonChars(p);
    for(auto i:q){
        cout << i << ", ";
    }
    cout << endl;
}