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