<!--
 * @Author: Z-Es-0 zes18642300628@qq.com
 * @Date: 2024-10-06 16:03:05
 * @LastEditors: Z-Es-0 zes18642300628@qq.com
 * @LastEditTime: 2024-10-06 21:59:45
 * @FilePath: \Algorithm-learning-and-communication\复健\Treepruning.md
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
[tree/bfs](https://codeforces.com/problemset/problem/2018/C)

## bfs / 模拟

我们可以从小到大枚举每一个深度，通过一个bfs实现，然后维护我们遍历过的点的数量sum,

还有当我们枚举的当前深度前面的需要删除的点数量die;

对于当前深度需要删除点的数量为: n - (sum - die) ;

对于变量die,我们可以维护出一个son_size数组记录下他们距离叶节点差几个孩子，每次遇见叶节点就向前为它的父节点的son_size - 1；

这样当son_size == 0 的时候 ， 就是叶节点了，我们又可以为这个节点的父亲做son_size-1的操作；

bfs实现即可

## code

```cpp

#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x & (-x))
#define N 500005
#define MOD (1e9+7)
int t, n, u, v;



void solve() {
    cin >> n;
    vector<vector<int>> tree(n + 1);
    vector<int> son_size(n + 1);
    map<int,int> father;


    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }


    queue<int> this_q;
    this_q.push(1);
    vector<bool> visited(n + 1, false);
    visited[1] = true;

    while (!this_q.empty()) {
        int y = this_q.front();
        this_q.pop();
        for (int i : tree[y]) {
            if (!visited[i]) {
                visited[i] = true;
                father[i] = y;
                this_q.push(i);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        son_size[i] = (int)tree[i].size() - 1;
        if (i == 1) son_size[i] = (int)tree[i].size();
    }

    vector<int> cheng = {1};
    vector<int>willdie;
    vector<int>op;
    int die = 0, sum = 1;
    int ans = n;
    while (!cheng.empty()) {
        willdie.clear();
        for (int i : cheng) {
            if (son_size[i] ==0){
                willdie.push_back(i);
                die++;
            }
        }
        op.clear();
        while (!willdie.empty()){
            for (int i : willdie) {
                son_size[father[i]]--;
                if (son_size[father[i]] == 0 ){
                    die++;
                    op.push_back(father[i]);
                }
            }
            willdie.clear();
            for (int i : op) {
                willdie.push_back(i);
            }
            op.clear();
        }
        for (int i :cheng) {
            for (int j : tree[i]) {
                if (j != father[i]){
                    op.push_back(j);
                    sum++;
                }

            }
        }
        cheng.clear();
        for (int i : op) {
            cheng.push_back(i);
        }
        ans = min(ans , n - (sum - die));
    }

    cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```
