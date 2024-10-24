#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lowbit(x) (x&(-x))

class UnionFind {
private:
    vector<int> parent, rank;
    int count;

public:
    // 初始化并查集
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0); // 初始化父节点为自己
        count = n;
    }


    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // 合并两个集合
    void union_sets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            count--;
        }
    }


    int getCount() const {
        return count;
    }
};


#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
template <typename T>
inline void read(T& r) {
    r=0;bool w=0; char ch=getchar();
    while(ch<'0'||ch>'9') w=ch=='-'?1:0,ch=getchar();
    while(ch>='0'&&ch<='9') r=r*10+(ch^48), ch=getchar();
    r=w?-r:r;
}


void solve() {
    int n;
    read(n);
    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        read(s[i]);
    }
    map<int,int>sp;
    for (int i = 0; i < 61; ++i) {
        sp[1<<i]=0;
    }
    int ans =0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 0){
            ans++;
            continue;
        }
        sp[lowbit(s[i])]|=s[i];
    }
    int size = 0;
    for (int i = 0; i < 61; ++i) {
        if (sp[1ll<<i]>0){
            size++;
        }
    }
    vector<int>ned(size);
    int l = 0;
    for (int i = 0; i < 61; ++i) {
        if (sp[1ll<<i]>0){
            ned[l]=sp[1ll<<i];
            l++;
        }
    }
    n=ned.size();
    UnionFind uf(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 61; ++j) {
            if (ned[i] & (1LL << j)) {
                if (mp.count(j)) {
                    uf.union_sets(mp[j], i);
                } else {
                    mp[j] = i;
                }
            }
        }
    }

    cout << uf.getCount()+ans << endl;

}

signed main() {
//    int t = fast_input();
//    while (t--) {
    solve();
//    }
    return 0;
}