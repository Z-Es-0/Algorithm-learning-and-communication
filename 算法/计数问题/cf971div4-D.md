<!--
 * @Author: Z-Es-0 zes18642300628@qq.com
 * @Date: 2024-09-04 12:02:51
 * @LastEditors: Z-Es-0 zes18642300628@qq.com
 * @LastEditTime: 2024-09-04 12:13:49
 * @FilePath: \Algorithm-learning-and-communication\算法\计数问题\cf971div4.md
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
[计算几何/计数](https://codeforces.com/contest/2009/problem/D)

## 观察问题

发现yi∈{0,1};那么非常简单了！

## 解决方案

1. 对于 {x,y},如果存在点 {x,!y}(对y取相反的值，0->1,1->0); 那么ans+= y相同的点数量 -1； 

2. 对于{x,y}如果 {x+-1,!y}存在 ans++;

## 证明

情况1：

我们钦定点{x,y}为直角，那么另外两个点可以是(x+-?,y),{x,!y}; 因为{x,!y}是唯一的，所以根据组合原理答案是 1*count((x+-?,y));

情况2：

依然钦定点{x,y}为直角， 因为另外两个点的坐标一定是整数，那么只有"1:1:sqrt(2)"符合整数的情况，也就是 {x+-1,!y}，一组；

## code

```cpp

#include "bits/stdc++.h"
using namespace std;
#define int long long
constexpr int N = 200005;
constexpr int MOD = 1000000007;
int t,n;
pair<int ,int >s[N];
bool ck[N][2];
void solve(){
    cin>>n;
    int q0=0,q1=0;
    int ans=0;
    memset(ck,0,sizeof ck);
    for (int i = 0; i < n; ++i) {
        cin>>s[i].first>>s[i].second;
        if(s[i].second==0){
            q0++;
        }
        else{
            q1++;
        }
        ck[s[i].first][s[i].second]= true;
    }
    for (int i = 0; i < n; ++i) {
        if(s[i].second==0){
            if (ck[s[i].first][1]){
                ans+=q0-1;
            }
            if (s[i].first>0 && ck[s[i].first+1][1] && ck[s[i].first-1][1]){
                ans++;
            }
        }
        else{
            if (ck[s[i].first][0]){
                ans+=q1-1;
            }
            if (s[i].first>0 && ck[s[i].first+1][0] && ck[s[i].first-1][0]){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}

signed main(){
    cin>>t;
    while (t--){
        solve();
    }
    return 0;
}
```