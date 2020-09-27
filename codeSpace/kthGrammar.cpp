#include <istream>
#include <vector>

using namespace std;
class Solution{
public:
    int kthGrammar(int N, int K) {
        if(N==1){
            return 0;
        }
        bool res = false;
        while(K!=0){
            if(K&&0x1==1){
                res = !res;
            }
            K >> 1;
        }
        return static_cast<int>(res);
    }
};


int main(){

}