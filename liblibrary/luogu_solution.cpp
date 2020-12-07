//
// Created by WOOO on 2020/12/7.
//

#include "luogu_solution.h"
void Luogu_solution::Luogu_P1803() {
    //===========开始录入数据=======================
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<int>> bombs(x, vector<int>(4));
    vector<vector<int>> strongholds(y, vector<int>(2));
    vector<vector<int>> res(y, vector<int>(2, 0));
    for (int i = 0; i < x; ++i) cin >> bombs[i][0] >> bombs[i][1] >> bombs[i][2] >> bombs[i][3];
    for (int i = 0; i < y; ++i) cin >> strongholds[i][0] >> strongholds[i][1];
    //===========录入数据结束=======================
    for (int i = 0; i < x; ++i) { // 扔炸弹模拟
        auto bomb = bombs[i];   // 取出炸弹
        for (int j = 0; j < y; ++j) {   // 判断每个点是否在范围内
            auto point = strongholds[j];
            // (0,0)点在左上角
            if ((point[0] >= bomb[0]) &&
                (point[0] <= bomb[2]) &&
                (point[1] <= bomb[3]) &&
                (point[1] >= bomb[1])) {
                res[j][0]++;    // 次数+1
                res[j][1] = i + 1;  // 记录最后一次的编号,起始为1
            }
        }
    }
    //===========打印计算结果=======================
    for (auto &r : res) {
        if (r[0] > 0) {
            cout << "Y " << r[0] << ' ' << r[1] << "\n";
        } else {
            cout << "N\n";
        }
    }
    //===========打印结果完成=======================
}