<!--
 * @Author: Z-Es-0 zes18642300628@qq.com
 * @Date: 2024-10-13 17:04:06
 * @LastEditors: Z-Es-0 zes18642300628@qq.com
 * @LastEditTime: 2024-10-13 17:06:30
 * @FilePath: \Algorithm-learning-and-communication\复健\Sheriff's Defense.md
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
[树上dp](https://codeforces.com/contest/2014/problem/F)

## tree
状态定义: dp0,dp1
表示不选和选当前节点;

dp，我们发现dp0[i]的转移直接max(dp0[j],dp1[j]);

dp1[i] 为 max(dp0[j],dp1[j]-2*c);


## code

```cpp

#include <bits/stdc++.h>

using namespace std;
#define int long long
#define lowbit(x) x&(-x)
#define N 100005
int n, t, c, u, v;

vector<int> treeTopSort(const vector<vector<int>>& adjList, vector<int>&father,int root = 1) {
    queue<int> q;
    vector<int> ans;
    vector<bool> visited(adjList.size(), false);  // 标记节点是否已访问

    q.push(root);                    // 将根节点入队
    visited[root] = true;            // 标记根节点为已访问
    father[root] = -1;               // 根节点没有父节点，设为 -1

    while (!q.empty()) {
        int co = q.front();          // 获取当前节点
        ans.push_back(co);           // 将当前节点加入结果集
        q.pop();                     // 移出队列

        for (int i : adjList[co]) {
            if (!visited[i]) {       // 如果该邻居节点未访问过
                q.push(i);           // 将子节点入队
                visited[i] = true;   // 标记子节点已访问
                father[i] = co;      // 记录父节点
            }
        }
    }

    reverse(ans.begin(), ans.end());  // 逆序结果
    return ans;
}

void solve() {
    cin>>n>>c;
    vector<int>a(n+1);
    vector<vector<int>>tree(n+1);
    vector<int>top;
//    vector<bool>check(n+1, false);
    vector<int>father(n+1);
    vector<int>dp0(n+1);
    vector<int>dp1(n+1);
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
    }
    for (int i = 0; i < n-1; ++i) {
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    top = treeTopSort(tree,father);

    for (int i : top) {
        if (i!=1 && tree[i].size()==1){
            dp1[i]=a[i];
        }
        else{
            dp1[i]=a[i];
            for (int j : tree[i]) {
                dp0[i]+=max(dp0[j],dp1[j]);
                dp1[i]+=max(dp0[j],dp1[j]-2*c);
            }

        }
    }
    cout<<max(dp0[1],dp1[1])<<endl;
}


signed main() {
    cin>>t;
    while (t--){
    solve();
    }
    return 0;
}
```