/*
 * @Author: Z-Es-0 141395766+Z-Es-0@users.noreply.github.com
 * @Date: 2024-07-31 15:40:09
 * @LastEditors: Z-Es-0 141395766+Z-Es-0@users.noreply.github.com
 * @LastEditTime: 2024-08-03 20:54:19
 * @FilePath: \Algorithm-learning-and-communication\算法模板cpp\拓扑排序vv.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

vector<int> topologicalSort(const vector<vector<int>>& adjList) { //v<v<i>>表示邻接表，即father ->son;
    int n = adjList.size();
    vector<int> indegree(n, 0);
    vector<int> result;
    unordered_map<int, vector<int>> reversedAdjList;


    for (int i = 1; i < n; ++i) {
        for (int node : adjList[i]) {
            reversedAdjList[node].push_back(i);
            indegree[i]++;
        }
    }


    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i < n; ++i) {
        if (indegree[i] == 0) {
            pq.push(i);
        }
    }


    while (!pq.empty()) {
        int node = pq.top();
        pq.pop();
        result.push_back(node);

        for (int neighbor : reversedAdjList[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                pq.push(neighbor);
            }
        }
    }

    return result;
}