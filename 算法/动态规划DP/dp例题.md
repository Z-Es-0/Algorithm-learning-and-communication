[P1434 [SHOI2002] 滑雪](https://www.luogu.com.cn/problem/P1434)

## dp+类似于bfs的枚举

题干:

```
Michael 想知道在一个区域中最长的滑坡。区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子：

1   2   3   4   5
16  17  18  19  6
15  24  25  20  7
14  23  22  21  8
13  12  11  10  9
一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度会减小。在上面的例子中，一条可行的滑坡
```

我们观察题目，要求是从大到小的最长序列，而且我们知道每个点可以向上下左右进行移动；

同理，对于每个点也只能由上下左右转移而来；

那么我们可以直接看出状态转移方程:

dp[i][j]=max(dp[i-1][j],dp[i+1][j],dp[i][j+1],dp[i][j-1]) //这是错误的！

正确的:

在这4个位置中，只有值大于点[i][j]的点才可以进行状态转移那么我们可以这样写：

通过循环更新最大值确定dp[i][j]的答案

```python
    for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
        nx, ny = x + dx, y + dy
        if g[nx][ny] > g[x][y]:#值大于点[i][j]的情况
            dp[nx][ny] = max(dp[nx][ny], dp[x][y] + 1)
```

```cpp
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
for(int d = 0; d < 4; ++d) {
    int nx = x + dx[d], ny = y + dy[d];
    if(g[nx][ny] > g[x][y]) { // 如果相邻点的值大于当前点的值
        dp[nx][ny] = max(dp[nx][ny], dp[x][y] + 1);
    }
}
```

到此我们解决了状态转移方程的问题，

但是我们依然对遍历顺序感到迷茫；如何找到正确的遍历顺序呢？

我们回归dp问题的概念；其中一个重要但是经常被不是那么熟悉dp的同学忽略的一点是[无后效性](无后效性)；

后面的决策不能受之前状态的影响；结合这道题我们得到一个方案：

最小的点进行状态转移得到的答案一定是1；然后对次小的点进行状态转移；这时次小的点完全是完整的正确答案不再会受未来的任何决策影响；

继续对次次小的点进行状态转移，次次次小...

于是我们得到了遍历顺序：从高度小到大进行状态转移；

只需要记录下从小到大的高度排序后遍历进行状态转移最后找到最大值就是答案；

代码py:


```python
r, c = map(int, input().split())
wht = []
dp = [[1 for _ in range(c)] for _ in range(r)]
g = []
for i in range(r):
    row = list(map(int, input().split()))
    g.append(row)
    for j in range(c):
        wht.append((row[j], i, j))
q = sorted(wht, key=lambda x: x[0])
for height, x, y in q:
    for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
        nx, ny = x + dx, y + dy
        if 0 <= nx < r and 0 <= ny < c and g[nx][ny] > g[x][y]:
            dp[nx][ny] = max(dp[nx][ny], dp[x][y] + 1)
print(max(max(row) for row in dp))

```


cpp

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> g(r, vector<int>(c));
    vector<vector<int>> dp(r, vector<int>(c, 1));
    vector<tuple<int, int, int>> wht;

    // 读入矩阵，并将值及其坐标放入数组中
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> g[i][j];
            wht.emplace_back(g[i][j], i, j);
        }
    }

    // 根据高度排序
    sort(wht.begin(), wht.end());

    // 更新dp数组
    for (auto& [height, x, y] : wht) {
        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && g[nx][ny] > g[x][y]) {
                dp[nx][ny] = max(dp[nx][ny], dp[x][y] + 1);
            }
        }
    }

    // 找到dp数组中的最大值
    int result = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            result = max(result, dp[i][j]);
        }
    }

    cout << result << endl;
    return 0;
}
```

复杂度：O(rclogrc)因为排序


 <a name="无后效性">什么是后效性？</a>

无后效性：某阶段的状态一旦确定，则此后过程的决策不再受此前各种状态及决策的影响。

有后效性：就是某个状态之后要做的决策会受之前的状态及决策的影响。
