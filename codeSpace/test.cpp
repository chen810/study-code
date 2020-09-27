#include <iostream>
using namespace std;
int main(){
    int a;
    cin >> a;
    int p[a];
    for(int i=0;i<a;++i){
        p[i] = i;
    }
    for(int i=0;i<a;++i){
        cout << p[i]<<" ";
    }
    cout << endl;
}