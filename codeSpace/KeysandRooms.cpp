// 841. Կ���뷿��
/**
 * �� N �����䣬��ʼʱ��λ�� 0 �ŷ��䡣ÿ�������в�ͬ�ĺ��룺0��1��2��...��N-1
 * ���ҷ����������һЩԿ����ʹ�������һ������
 * ����ʽ�ϣ�����ÿ������ i ����һ��Կ���б� rooms[i]
 * ÿ��Կ�� rooms[i][j] �� [0,1��...��N-1] �е�һ��������ʾ
 * ���� N = rooms.length�� Կ�� rooms[i][j] = v ���Դ򿪱��Ϊ v �ķ���
 * ������� 0 �ŷ�������������з��䶼����ס
 * ��������ɵ��ڷ���֮�������߶�
 * ����ܽ���ÿ�����䷵�� true�����򷵻� false
 * */

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();   // ������
        bool *keySign = new bool[n]();  // ���Կ���Ƿ��õ�
        keySign[0] = true;  // 0�ŷ�Կ��һֱ����
        queue<int> keys;    // Կ�״�
        keys.push(0);   // ����0��Կ��
        while(!keys.empty()){   // ѭ���򿪷���
            int key = keys.front(); //��Կ�״����ó�Կ��
            keys.pop(); // �Ӵ�ѡԿ�״���ȥ��
            for(auto i:rooms[key]){ //�������ó�û�õ���Կ��
                if(!keySign[i]){
                    keys.push(i);
                    keySign[i] = true;
                }
            }
        }
        for(int i=0;i<n;i++){   // ��Կ��,��Կ��û�õ�˵���з����޷�����
            if(!keySign[i]){
                return false;
            }
        }
        return true;
    }
};