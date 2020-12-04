// 841. 钥匙与房间
/*
 * 有 N 个房间，开始时你位于 0 号房间。每个房间有不同的号码：0，1，2，...，N-1
 * 并且房间里可能有一些钥匙能使你进入下一个房间
 * 在形式上，对于每个房间 i 都有一个钥匙列表 rooms[i]
 * 每个钥匙 rooms[i][j] 由 [0,1，...，N-1] 中的一个整数表示
 * 其中 N = rooms.length。 钥匙 rooms[i][j] = v 可以打开编号为 v 的房间
 * 最初，除 0 号房间外的其余所有房间都被锁住
 * 你可以自由地在房间之间来回走动
 * 如果能进入每个房间返回 true，否则返回 false
 * */

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms) {
        int n = rooms.size();   // 房间数
        bool *keySign = new bool[n]();  // 标记钥匙是否拿到
        keySign[0] = true;  // 0号房钥匙一直存在
        queue<int> keys;    // 钥匙串
        keys.push(0);   // 加入0号钥匙
        while (!keys.empty()) {   // 循环打开房间
            int key = keys.front(); //从钥匙串中拿出钥匙
            keys.pop(); // 从待选钥匙串中去除
            for (auto i:rooms[key]) { //房间里拿出没拿到的钥匙
                if (!keySign[i]) {
                    keys.push(i);
                    keySign[i] = true;
                }
            }
        }
        for (int i = 0; i < n; i++) {   // 数钥匙,有钥匙没拿到说明有房间无法进入
            if (!keySign[i]) {
                return false;
            }
        }
        return true;
    }
};