#include <iostream>
#include <string>
#include "leetcode_solution.h"
using namespace std;
int main() {
    int k=1;
    for(int i=0;i<1000;i+=k){
        k++;
    }
    cout << k << "ok" << endl;
    cout << Solution::addStrings("123","467")<<endl;
}