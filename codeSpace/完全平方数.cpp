/** ���������� n���ҵ����ɸ���ȫƽ���������� 1, 4, 9, 16, ...��
 * ʹ�����ǵĺ͵��� n������Ҫ����ɺ͵���ȫƽ�����ĸ�������
 * */
#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
    int numSquares(int n) {
        int *temp = new int[n+1]();
        for(int i=1;i<=n;++i){
                int sqrt4i = sqrt(i);
                if(sqrt4i*sqrt4i==i){
                    temp[i] = 1;
                    continue;
                }
                int left = 1;
                int leftDouble = 1;
                int s = temp[leftDouble]+temp[i-leftDouble];
                while(2*leftDouble<=i){
                    int tt = temp[leftDouble]+temp[i-leftDouble];
                    s = s>tt?tt:s;
                    left++;
                    leftDouble = left * left;
                }
                temp[i] = s;
            }
        return temp[n]; 
    }
};