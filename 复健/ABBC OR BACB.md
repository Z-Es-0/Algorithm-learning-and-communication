<!--
 * @Author: Z-Es-0 zes18642300628@qq.com
 * @Date: 2024-10-18 17:47:31
 * @LastEditors: Z-Es-0 zes18642300628@qq.com
 * @LastEditTime: 2024-10-18 18:43:35
 * @FilePath: \Algorithm-learning-and-communication\复健\ABBC OR BACB.md
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
[构造](https://codeforces.com/contest/1873/problem/G)

## 观察到

我们对于一个AAA....AABA...AA..形式的序列可以让B向左或者向右扩展到结尾

那么我们考虑原序列里B的分布情况:

有我们不得不舍去的俩个b之间的一段a，b包含起点和终点，那么我们只需找到最小的BB区间差的数量即可

## code
```cpp

#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define lowbit(x) (x & (-x))
#define N 1000005
#define MOD (1e9+7)
int t,n,k;
void solve(){
    string s;
    int ans=INT32_MAX;
    cin>>s;
    int lst = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'B'){
            ans = min(ans, i-lst-1);
            lst = i;
        }
    }
    ans = min(ans,(int)s.size() - lst -1 );

    cout<< std::count(s.begin(), s.end(),'A')-ans<<endl;
}
signed main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
cin>>t;
while(t--){
    solve();
 }
return 0;
}

```