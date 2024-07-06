[石子合并](https://www.luogu.com.cn/problem/P1775)


观察到，一个三维dp可以解决

```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans,n;
int s[305],qz[305];
int dp[305][305];
int a,b,r;
void solve(){
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>s[i];

        r+=s[i];
        qz[i+1]=r;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n-i; ++j) {
            a=j;b=j+i;
//            cout << "a and b is" << ' ' << a << ' ' << b << endl;

             {
                int mn = LLONG_MAX;
                for (int k = a ; k < b; ++k) {
                    int p;
                    p=dp[a][k]+dp[k+1][b]+qz[b+1]-qz[a];
                    mn=min(mn,p);
//                    cout<<p<<' '<<a <<' '<<k <<endl;
                }
                dp[a][b]=mn;
            }

        }
    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            cout<<dp[i][j]<<' ';
//        }
//        cout<<endl;
//    }
    cout<<dp[0][n-1]<<endl;
}
signed main(){

    solve();
    return 0;
}
```