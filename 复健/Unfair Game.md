<!--
 * @Author: Z-Es-0 zes18642300628@qq.com
 * @Date: 2024-10-27 22:07:03
 * @LastEditors: Z-Es-0 zes18642300628@qq.com
 * @LastEditTime: 2024-10-27 22:08:50
 * @FilePath: \Algorithm-learning-and-communication\复健\Unfair Game.md
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
[Unfair Game](https://codeforces.com/contest/1955/problem/F)

## 伪博弈

注意到 xor为0的操作只有 自己xor 自己 或者 1^2^3；

那么直接枚举操作几次1^2^3

## code

```cpp
#include <bits/stdc++.h>
using namespace std;
//#define int long long
int n,a,b,c,d;
void solve() {
    cin>>a>>b>>c>>d;
    int ans = a/2+b/2+c/2+d/2;
    for (int i = 0; i <= min(min(a,b),c); ++i) {
        ans = max(ans,i+(a-i)/2+(b-i)/2+(c-i)/2+d/2);
    }
    cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
```