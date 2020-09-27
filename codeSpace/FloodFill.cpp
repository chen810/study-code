// 733.ͼ����Ⱦ
/**
 * ��һ���Զ�ά���������ʾ��ͼ����ÿһ��������ʾ��ͼ��������ֵ��С����ֵ�� 0 �� 65535 ֮��
 * ����һ������ (sr, sc) ��ʾͼ����Ⱦ��ʼ������ֵ���� ���У���һ���µ���ɫֵ newColor������������ɫ���ͼ��
 * Ϊ�������ɫ�������ӳ�ʼ���꿪ʼ����¼��ʼ��������������ĸ�����������ֵ���ʼ������ͬ���������ص�
 * �����ټ�¼���ĸ������Ϸ������������ص������Ƕ�Ӧ�ĸ�����������ֵ���ʼ������ͬ���������ص�
 * �ظ��ù��̡��������м�¼�����ص����ɫֵ��Ϊ�µ���ɫֵ
 * ��󷵻ؾ�����ɫ��Ⱦ���ͼ��
 * */
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int row = image.size(); 
        int col = image[0].size();  // ��¼ͼ���С
        int rawColor = image[sr][sc];   // ��¼��ʼ��ɫ
        queue<vector<int>> temp;    // ����δȾɫ����
        temp.push({sr,sc}); // ������ʼ��
        while(!temp.empty()){   // �ظ��ж�,ֱ��������δȾɫ����
            int i = temp.front()[0];    // ȡ����һ��δȾɫ�������
            int j = temp.front()[1];    // ȡ����һ��δȾɫ��������
            image[i][j] = newColor; // Ⱦɫ
            temp.pop(); // ɾ��Ⱦɫ��ɵ�
            if(i-1>=0&&image[i-1][j]==rawColor&&image[i-1][j]!=newColor){    // �����ĸ�����ĵ�,����:������,����ʼ����ͨ,δȾɫ
                temp.push({i-1,j});
            }
            if(i+1<row&&image[i+1][j]==rawColor&&image[i+1][j]!=newColor){
                temp.push({i+1,j});
            }
            if(j-1>=0&&image[i][j-1]==rawColor&&image[i][j-1]!=newColor){
                temp.push({i,j-1});
            }
            if(j+1<col&&image[i][j+1]==rawColor&&image[i][j+1]!=newColor){
                temp.push({i,j+1});
            }
        }
        return image;
    }
};