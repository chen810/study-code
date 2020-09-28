// KMP算法

#include <vector>
#include <string>
using namespace std;

vector<int> next(string p){
    vector<int> temp(p.size(),-1);
    for(int i=1;i<p.size();++i){
        int j = temp[i-1];
        while(j!=-1&&p[i]!=p[j+1]){
            j = temp[j];
        }
        if(p[i]==p[j+1]){
            temp[i] = j+1;
        }
    } 
    return temp;
}