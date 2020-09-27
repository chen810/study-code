#include <iostream>
#include "test.h"
using namespace std;
int main(int, char**) {
    std::cout << "Hello, world!\n";
    Test p;
    for(int i=0;i<10;++i){
        p.func();
    }
    int k;
    cin >> k; 
}
