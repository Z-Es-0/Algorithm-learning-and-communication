/*
 * @Author: Z-Es-0 141395766+Z-Es-0@users.noreply.github.com
 * @Date: 2024-08-19 20:39:17
 * @LastEditors: Z-Es-0 141395766+Z-Es-0@users.noreply.github.com
 * @LastEditTime: 2024-08-19 20:39:24
 * @FilePath: \Algorithm-learning-and-communication\算法模板cpp\优先队列dij.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// 使用优先队列优化的 Dijkstra 算法
void dijkstra(int n, int m, int s, vector<vector<pair<int, long long>>>& adj, vector<long long>& dist) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist.assign(n + 1, LLONG_MAX); // 初始化距离数组
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& [v, weight] : adj[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<pair<int, long long>>> adj(n + 1); // 邻接表

    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); // 存储边
    }

    vector<long long> dist;
    dijkstra(n, m, s, adj, dist);

    // 输出结果
    for (int i = 1; i <= n; i++) {
        cout << (dist[i] == LLONG_MAX ? -1 : dist[i]) << " ";
    }
    cout << endl;

    return 0;
}
