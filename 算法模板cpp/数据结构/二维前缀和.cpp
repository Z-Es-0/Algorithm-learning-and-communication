/*
 * @Author: Z-Es-0 zes18642300628@qq.com
 * @Date: 2024-07-29 00:03:22
 * @LastEditors: Z-Es-0 zes18642300628@qq.com
 * @LastEditTime: 2024-09-07 23:11:29
 * @FilePath: \Algorithm-learning-and-communication\算法模板cpp\数据结构\二维前缀和.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define lowbit(x) (x & (-x))
#define M 100005
#define N 1005
#define MOD (1e9+7)
int t,n;


int s[N][N],qz[N][N]; //s是原数组，qz是二维前缀和数组

void build(int rows, int cols) { //范围，二维数组大小
    memset(qz, 0, sizeof(int) * M * M);
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= cols; ++j) {
            qz[i][j] = s[i][j]
                       + qz[i-1][j]
                       + qz[i][j-1]
                       - qz[i-1][j-1];
        }
    }
}

int finds(int r1, int c1, int r2, int c2) {//查询，直接传需要查询的区间，不用-1；（得用索引值+1即第几个数
    return qz[r2][c2]
           - (r1 > 1 ? qz[r1-1][c2] : 0)
           - (c1 > 1 ? qz[r2][c1-1] : 0)
           + (r1 > 1 && c1 > 1 ? qz[r1-1][c1-1] : 0);
}