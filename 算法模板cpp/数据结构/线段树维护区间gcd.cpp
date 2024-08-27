#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define lowbit(x) (x & (-x))
#define N 100005
#define MOD (1e9+7)
int t,n;
//begin
class SegmentTree {
private:
    std::vector<int> tree;
    std::vector<int> arr;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            // Leaf node will have a single element
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            // Recursively build the segment tree
            build(2*node+1, start, mid);
            build(2*node+2, mid+1, end);
            // Internal node will have the gcd of both of its children
            tree[node] = std::gcd(tree[2*node+1], tree[2*node+2]);
        }
    }

    void update(int idx, int val, int node, int start, int end) {
        if (start == end) {
            // Leaf node
            arr[start] = val;
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {

                update(idx, val, 2*node+1, start, mid);
            } else {

                update(idx, val, 2*node+2, mid+1, end);
            }

            tree[node] = std::gcd(tree[2*node+1], tree[2*node+2]);
        }
    }

    int query(int L, int R, int node, int start, int end) {
        if (R < start || end < L) {
            return 0;
        }
        if (L <= start && end <= R) {

            return tree[node];
        }

        int mid = (start + end) / 2;
        int left_child_gcd = query(L, R, 2*node+1, start, mid);
        int right_child_gcd = query(L, R, 2*node+2, mid+1, end);
        return std::gcd(left_child_gcd, right_child_gcd);
    }

public:
    SegmentTree(std::vector<int>& input) : arr(input) {
        n = input.size();
        tree.resize(4*n);
        build(0, 0, n-1);
    }

    void update(int idx, int val) {
        update(idx, val, 0, 0, n-1);
    }

    int query(int L, int R) {
        return query(L, R, 0, 0, n-1);
    }
};
//end;

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