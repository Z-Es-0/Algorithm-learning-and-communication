/*
 * @Author: Z-Es-0 zes18642300628@qq.com
 * @Date: 2024-09-15 21:37:59
 * @LastEditors: Z-Es-0 zes18642300628@qq.com
 * @LastEditTime: 2024-09-15 21:38:05
 * @FilePath: \Algorithm-learning-and-communication\算法模板cpp\数学\组合数.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <map>
using namespace std;

map<pair<int, int>, int> memo;

int C(int n, int m) {
 
    if (n == m || m == 0) {
        return 1;
    }

 
    if (memo.find({n, m}) != memo.end()) {
        return memo[{n, m}];
    }

    memo[{n, m}] = C(n - 1, m - 1) + C(n - 1, m);
    return memo[{n, m}];
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << C(n, m) << endl;
    return 0;
}
