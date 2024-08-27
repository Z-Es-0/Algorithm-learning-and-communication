

void finds(int node, int parent, const map<int, vector<int>>& adj, map<int, int>& parents) {
    parents[node] = parent;
    for (int neighbor : adj.at(node)) {
        if (neighbor != parent) {
            finds(neighbor, node, adj, parents);
        }
    }
}