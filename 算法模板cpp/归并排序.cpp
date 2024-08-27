/*
 * @Author: Z-Es-0 141395766+Z-Es-0@users.noreply.github.com
 * @Date: 2024-08-27 15:20:15
 * @LastEditors: Z-Es-0 141395766+Z-Es-0@users.noreply.github.com
 * @LastEditTime: 2024-08-27 15:23:04
 * @FilePath: \Algorithm-learning-and-communication\算法模板cpp\归并排序.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define lowbit(x) (x & (-x))
#define N 100005
#define MOD (1e9+7)
int t,n;
void merge_sort(vector<int>vec){
    
}
void solve(){
    vector<int>show ={9,2,3,8,6,1,7};
    merge_sort(show);
    for (int i = 0; i < show.size(); i++)
    {
        cout<<show[i]<<' ';
    }
    cout<<endl;
}
signed main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
//cin>>t;
//while(t--){
    solve();
// }
return 0;
}