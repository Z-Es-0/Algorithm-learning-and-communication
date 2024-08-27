/*
 * @Author: Z-Es-0 141395766+Z-Es-0@users.noreply.github.com
 * @Date: 2024-08-23 10:08:17
 * @LastEditors: Z-Es-0 141395766+Z-Es-0@users.noreply.github.com
 * @LastEditTime: 2024-08-23 23:51:17
 * @FilePath: \Algorithm-learning-and-communication\算法模板cpp\欧拉筛.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lowbit(x) (x & (-x))



#define M 100
vector<int>prime;
bool is_prime[M];//范围
void eulersiece(int n){//范围
    memset(is_prime,1,sizeof is_prime);
    for (int i = 2; i < n+1; ++i) {
        if (is_prime[i]){
            prime.push_back(i);
        }
        for (int j : prime) {
            if (i*j>n){
                break;
            }
            is_prime[i*j]= false;
            if (i%j==0){
                break;
            }
        }
    }
}

signed main(){
    eulersiece(100);
    for (int i : prime)
    {
        cout<<i<<' ';
    }
    
    return 0;
}


