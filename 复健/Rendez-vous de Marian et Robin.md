[dij](https://codeforces.com/contest/2014/problem/E)

## dij

双dij但是在dij里有特殊情况，如果遇见马就变快；


## code

```cpp
#include <bits/stdc++.h>  // 导入所有常用的标准库
using namespace std;

// Dijkstra算法实现，计算从源点src到每个节点的最短路径
// dist：存储每个节点的最短路径距离，g：图的邻接表，hs：节点是否为特殊节点
void dijk(int src, vector<vector<long long>> &dist, const vector<vector<pair<int, long long>>> &g, const vector<bool> &hs) {

    // 自定义比较函数，用于优先队列的排序
    auto cmp = [&](auto &a, auto &b) {
        return make_pair(dist[a.first][a.second], a) < make_pair(dist[b.first][b.second], b);
    };
    
    // 定义优先队列，使用自定义的比较函数cmp
    set<pair<int, int>, decltype(cmp)> pq(cmp);

    dist[src][0] = 0;  // 初始化源点的距离为0，且非特殊路径
    pq.insert({src, 0});  // 将源点加入优先队列

    // 开始Dijkstra算法
    while (!pq.empty()) {
        // 取出优先队列中当前距离最小的节点
        auto [cur, hcur] = *pq.begin();
        pq.erase(pq.begin());  // 删除该节点

        // 判断当前路径是否经过特殊节点
        bool ish = hcur || hs[cur];

        // 遍历当前节点的所有邻居
        for (const auto &[nxt, len] : g[cur]) {
            // 如果当前路径经过特殊节点，则边权减半
            long long new_dist = ish ? len / 2 : len;

            // 如果到下一个节点的距离可以被更新
            if (dist[nxt][ish] > dist[cur][hcur] + new_dist) {
                pq.erase({nxt, ish});  // 删除之前记录的该节点
                dist[nxt][ish] = dist[cur][hcur] + new_dist;  // 更新距离
                pq.insert({nxt, ish});  // 将更新后的节点重新插入优先队列
            }
        }
    }
}

// 主逻辑函数，处理每个测试用例
void solve() {
    int n, m, h;
    cin >> n >> m >> h;  // 输入节点数n、边数m、特殊节点数h

    vector<bool> hs(n, false);  // 标记每个节点是否为特殊节点

    // 图的邻接表表示，g[i]存储从节点i出发的所有边（邻居节点和边的权重）
    vector<vector<pair<int, long long>>> g(n);

    // 输入特殊节点
    for (int i = 0; i < h; ++i) {
        int c;
        cin >> c;
        hs[--c] = true;  // 标记特殊节点
    }

    // 输入图的边
    for (int i = 0; i < m; ++i) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--, b--;  // 将1-based转为0-based
        g[a].emplace_back(b, c);  // 无向图，a到b
        g[b].emplace_back(a, c);  // b到a
    }

    // d1和d2用于存储从节点0和节点n-1出发的最短路径
    vector<vector<long long>> d1(n, vector<long long>(2, LLONG_MAX));  // d1[i][0]表示从0到i的最短距离（没马）
    vector<vector<long long>> d2(n, vector<long long>(2, LLONG_MAX));  // d2[i][1]表示从0到i的最短距离（特殊路径）

    dijk(0, d1, g, hs);     // 运行Dijkstra算法，从节点0开始
    dijk(n - 1, d2, g, hs); // 运行Dijkstra算法，从节点n-1开始

    long long best = LLONG_MAX;  // 初始化best为最大值，用于找最优解

    // 遍历每个节点，计算两次最短路径的最优解
    for (int i = 0; i < n; ++i) {
        // 计算从节点0到节点i的最小距离，以及从节点n-1到节点i的最小距离，取其中最大值
        best = min(best, max(min(d1[i][0], d1[i][1]), min(d2[i][0], d2[i][1])));
    }

    // 输出结果，如果best仍然是无穷大，表示无解，输出-1，否则输出最小值
    cout << (best == LLONG_MAX ? -1 : best) << '\n';
}


int main() {
    int t;
    cin >> t; 
    while (t--) {
        solve();  
    }
    return 0;
}
```