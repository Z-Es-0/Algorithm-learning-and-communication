#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define lowbit(x) (x & (-x))
#define N 100005
#define MOD (1e9+7)
int t,n;
//begin
class FrequencySegmentTree {
private:
    std::vector<std::map<int, int>> tree;
    std::vector<int> arr;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            // Leaf node will have a single element
            tree[node][arr[start]] = 1;
        } else {
            int mid = (start + end) / 2;
            build(2*node+1, start, mid);
            build(2*node+2, mid+1, end);
            // Merge operation
            for (const auto &entry : tree[2*node+1]) {
                tree[node][entry.first] += entry.second;
            }
            for (const auto &entry : tree[2*node+2]) {
                tree[node][entry.first] += entry.second;
            }
        }
    }

    int query(int L, int R, int k, int node, int start, int end) {
        if (R < start || end < L) {
            return 0;
        }
        if (L <= start && end <= R) {
            return tree[node][k];
        }
        int mid = (start + end) / 2;
        int left_query = query(L, R, k, 2*node+1, start, mid);
        int right_query = query(L, R, k, 2*node+2, mid+1, end);
        return left_query + right_query;
    }

public:
    FrequencySegmentTree(const std::vector<int>& input) : arr(input) {
        n = input.size();
        tree.resize(4*n);
        build(0, 0, n-1);
    }

    int query(int L, int R, int k) {
        return query(L, R, k, 0, 0, n-1);
    }
};
//end
void solve(){
      
}
signed main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
//cin>>t;
//while(t--){
    solve();
// }
return 0;
}