<!--
 * @Author: Z-Es-0 141395766+Z-Es-0@users.noreply.github.com
 * @Date: 2024-04-28 18:13:19
 * @LastEditors: Z-Es-0 141395766+Z-Es-0@users.noreply.github.com
 * @LastEditTime: 2024-08-03 21:06:04
 * @FilePath: \Algorithm-learning-and-communication\算法\图论\Floyd.md
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
An[i][j]:i->j的路径上所经过的顶点编号不大于k

> 最外层循环k的含义是 从 i 为起点 ，j为终点，经过k的最短路径

dpk[i][j]=min(dpk-1[i][j],ak-1[i][k]+ak-1[k][j])

```python
n,e=map(int,input().split())
inf=float('inf')
dp=[[inf for i in range(n+2)] for j in range(n+2)]
for _ in range(e):
    i,j,c=map(int,input().split())
    dp[i][j]=c
for i in range(1,n+1):
    dp[i][i]=0
for k in range(1,n+1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if i!=k and j!=i and j!=k and (dp[i][k]+dp[k][j]<dp[i][j]):
                dp[i][j]=dp[i][k]+dp[k][j]

for i in dp:
    print(i)
```

```cpp
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int n, e;
    cin >> n >> e;
    const int INF = numeric_limits<int>::max();

    // 创建一个n+1 x n+1的二维数组，并初始化为INF
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));

    // 读取边的信息并更新dp数组
    for (int i = 0; i < e; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        dp[u][v] = w;
    }

    // 将每个点到自身的距离设为0
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = 0;
    }

    // Floyd-Warshall算法
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i != k && j != i && j != k && dp[i][k] != INF && dp[k][j] != INF) {
                    if (dp[i][k] + dp[k][j] < dp[i][j]) {
                        dp[i][j] = dp[i][k] + dp[k][j];
                    }
                }
            }
        }
    }

    // 输出结果
    for (const auto& row : dp) {
        for (int val : row) {
            if (val == INF) {
                cout << "INF ";
            } else {
                cout << val << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
```