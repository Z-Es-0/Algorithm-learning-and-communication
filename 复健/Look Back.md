[Look Back](https://codeforces.com/contest/1883)

## 状压灵感

观察到 我们的数字有效的bit只有不到31bit，那么我们维护一个数组表示最高位1所在的位；

对于相同最高位而言只需要人为把最高位1设置在第31位，就可以比较他们的大小;

## code

```cpp

#include <bits/stdc++.h>

using namespace std;
//#define int uint64_t
#define lowbit(x) x&(-x)
#define N 100005

int n, t;


int leftmost_one(int x) { // higbit
    int ans = 0;
    for (int i = 0; i < 31; ++i) {
        if (((1<<i)&x)>0){
            ans = i;
        }
    }
    return ans;
}

bool check(int a ,int b){

    int a32=(a<<(31-leftmost_one(a)));
    int b32 = (b<<(31-leftmost_one(b)));

    return a32 > b32;
}
void solve() {
    cin>>n;
    vector<int>s(n),g(n);
    for (int i = 0; i < n; ++i) {
        cin>>s[i];
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        g[i] = leftmost_one(s[i]);
    }
//    for (int i = 0; i < n; ++i) {
//        cout<<g[i]<<' ';
//    }
//    cout<<endl;
    for (int i = 1; i < n; ++i) {
        if (g[i] < g[i-1]){
            ans += g[i-1]-g[i];
            g[i]=g[i-1];
            if (check(s[i-1],s[i])){
                ans++;
                g[i]++;
            }
        }
        else if (g[i] == g[i-1] && check(s[i-1],s[i])){
            ans++;
            g[i]++;
        }
    }
    cout<<ans<<endl;
}
signed main() {
    cin>>t;
    while (t--){
    solve();
    }
    return 0;
}
```