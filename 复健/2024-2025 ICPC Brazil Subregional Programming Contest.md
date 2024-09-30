<!--
 * @Author: Z-Es-0 zes18642300628@qq.com
 * @Date: 2024-09-29 20:41:52
 * @LastEditors: Z-Es-0 zes18642300628@qq.com
 * @LastEditTime: 2024-09-29 21:05:30
 * @FilePath: \Algorithm-learning-and-communication\xcpc训练\2024-2025 ICPC Brazil Subregional Programming Contest.md
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
[K](https://codeforces.com/gym/105327/problem/K)

# dp/思维

> Alice and Bob not play a game !(这个题目并不是博弈论！)

我们需要找到一种排序方式，使得在题目要求中得到alice = bob 的数量；

因为要平分，那么给我们的sum%2 == 0 才可行；

剩下的情况; 我们考虑如何构造出 alice == bob == sum/2;

我们发现， 我们只有ALICE AND BOB 俩集合，那么对于一个 值 只有俩种情况；

最先反应是子集枚举 ，直接可以表示状态，当然时间复杂度很高，不可行；

然后我们考虑对于一个值的情况，这个值一定在某个人的集合中，我们考虑这个值是这个集合的最后一个，那么有sum- s[i] 为集合除了它的和，这样就是一个子集划分dp的思路；

## 状态表示 

dp[i][j] 表示 考虑前i个元素的是否可能为j；

## 状态转移

对于 dp[i][j]，有两种情况：

不选第 i 个元素 s[i]：

如果前 i-1 个元素已经能凑出和 j，那么此时也能凑出和 j。
状态转移：dp[i][j] = dp[i-1][j]。
选第 i 个元素 s[i]：

如果在前 i-1 个元素中，能够凑出和 j - s[i]，那么加上元素 s[i]，就能凑出和 j。
状态转移：dp[i][j] = dp[i-1][j - s[i]] （前提是 j - s[i] >= 0）。

## 回溯寻找集合

我们通过判断是不是dp[i-1][cur_sum-s[i]] 来表示dp[i][j]是不是选择了当前的s[i];如果是即将这个s[i]纳入集合a,否则纳入b;

## print ans

模拟

## code

```cpp

/*
 * @Author: Z-Es-0 zes18642300628@qq.com
 * @Date: 2024-09-26 18:52:44
 * @LastEditors: Z-Es-0 zes18642300628@qq.com
 * @LastEditTime: 2024-09-29 20:48:40
 * @FilePath: \codeforces\one.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <bits/stdc++.h>
using namespace std;
#define N 105

int s[N];
bool dp[N][9000];  // 使用 dp[i][j] 记录是否能用前 i 个元素凑出和 j

void solve(){
    int n;
    cin >> n;
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        sum += s[i];
    }

    if (sum % 2 != 0) {
        cout << -1 << endl;
        return;
    }

    int target = sum / 2;

  
    dp[0][0] = true;  // 没有选任何元素时，和为 0 是可行的

    // 动态规划：更新 dp 数组
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            dp[i][j] = dp[i-1][j];  // 不选当前元素，继承前面的状态
            if (j >= s[i]) {
                dp[i][j] |= dp[i-1][j - s[i]];  // 选当前元素
            }
        }
    }

    // 如果无法凑成目标和，输出 -1
    if (!dp[n][target]) {
        cout << -1 << endl;
        return;
    }

    // 回溯找到两个子集
    vector<int> alice, bob;
    int cur_sum = target;
    for (int i = n; i >= 1; i--) {
        // 如果当前和是由 s[i] 构成的，选择 s[i]
        if (cur_sum >= s[i] && dp[i-1][cur_sum - s[i]]) {
            alice.push_back(s[i]);
            cur_sum -= s[i];
        } else {
            bob.push_back(s[i]);  // 否则放入 bob 集合
        }
    }

    // 输出两个子集
    sort(alice.begin(), alice.end());
    sort(bob.begin(), bob.end());

    int suma = 0, sumb = 0;
    int i = 0, j = 0;

    // 交替输出 alice 和 bob，确保 suma 和 sumb 尽量接近
    while (i < alice.size() || j < bob.size()) {
        if (suma <= sumb && i < alice.size()) {
            cout << alice[i++] << " ";
            suma += alice[i-1];
        } else if (j < bob.size()) {
            cout << bob[j++] << " ";
            sumb += bob[j-1];
        }
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
```