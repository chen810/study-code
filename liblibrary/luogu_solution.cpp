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

void Luogu_solution::Luogu_P2006(){
    //===========开始录入数据=======================
    int k,m,n;
    cin >> k>>m>>n;
    vector<vector<int>> info(m,vector<int>(2));
    for(int i=0;i<m;++i) cin >> info[i][0] >> info[i][1];
    //===========录入数据结束=======================
    vector<int> res;
    for(int i=0;i<m;++i){
        if(info[i][0]==0||info[i][0]<=k&&k*info[i][1]>=n*info[i][0]) res.push_back(i+1);
    }
    //===========打印计算结果=======================
    if(res.empty()){
        cout << -1 ;
    }else{
        for(auto &r : res) cout << r << " ";
    }
    //===========打印结果完成=======================
}

/*string itos(int n){
    if(n==0) return "0";
    string res;
    while(n>0){
        int t = n%10;
        n /= 10;
        res.push_back('0'+t);
    }
    reverse(res.begin(),res.end());
    return res;
}*/
void Luogu_solution::Luogu_P2084(){
    //===========开始录入数据=======================
    string k,s;
    cin >> k >>s;
    // cout << k << " " <<s << "\n";
    //===========录入数据结束=======================
    string res;
    int n = s.size();
    bool flag = false;
    for(int i=0;i<s.size();++i){
        if(s[i]!='0'){
            if(flag) res += "+";
            res += s[i];
            res += "*"+k+"^"+to_string(n-1-i);
            flag = true;
        }
    }
    //===========打印计算结果=======================
    cout << res;
    //===========打印结果完成=======================
}