#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int Find(vector<int>& parent, int index) {  // 返回parent[index]的值,顺便更新最新节点的分组
        if (parent[index] != index) { // 如果被分组过则进行再次分组
            parent[index] = Find(parent, parent[index]);    // 
        }
        return parent[index];
    }
    void Union(vector<int>&parent, int index1, int index2){ // 两个分组合一
        parent[Find(parent, index1)] = Find(parent, index2);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();   // n条边
        vector<int> parent(n + 1);  // n个节点
        for (int i = 1; i <= n; ++i) {  // 初始单独分组
            parent[i] = i;
        }
        for (auto& i : edges) { // 寻找冲突
            int node1 = i[0], node2 = i[1];
            if (Find(parent, node1) != Find(parent, node2)) {
                Union(parent, node1, node2);
            }
            else {
                return i;   // 返回冲突
            }
        }
        return vector<int>{};
    }
};
int main() {
    vector<vector<int>> p{ {1,2},{1,3},{2,3} };
    Solution t;
    auto q = t.findRedundantConnection(p);
    cout << q[0] << "," << q[1] << endl;
}