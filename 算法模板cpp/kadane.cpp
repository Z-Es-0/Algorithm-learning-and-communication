/*
 * @Author: Z-Es-0 141395766+Z-Es-0@users.noreply.github.com
 * @Date: 2024-07-13 23:40:36
 * @LastEditors: Z-Es-0 141395766+Z-Es-0@users.noreply.github.com
 * @LastEditTime: 2024-08-25 20:41:06
 * @FilePath: \Algorithm-learning-and-communication\算法模板cpp\kadane.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define lowbit(x) (x & (-x))
#define N 100005
#define MOD (1e9+7)
int t,n;



int kadane(const vector<int> arr,int x){
    int cmax=arr[0];
    int gmax=arr[0];
    for (int i = 1; i < x; ++i) {
        cmax=max(arr[i],cmax+arr[i]);
        gmax=max(gmax,cmax);
    }
    return gmax;

}



