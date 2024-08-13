<!--
 * @Author: Z-Es-0 141395766+Z-Es-0@users.noreply.github.com
 * @Date: 2024-08-11 19:33:43
 * @LastEditors: Z-Es-0 141395766+Z-Es-0@users.noreply.github.com
 * @LastEditTime: 2024-08-11 19:41:00
 * @FilePath: \Algorithm-learning-and-communication\算法\动态规划DP\概率dp.md
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
[概率dp](https://codeforces.com/contest/453/problem/A)

> 推了3个小时没推出来

## 分析

考虑m面骰子n次；明显有m^n种情况；

再看期望咋算 sum(情况)/m^n; 

把括号上面拆开 ：sum( m*P(m1) )

再考虑P(m1)咋算

P(k) = (k/m)^n - ((k-1)/m)^n;

(k/m)^n表示的不就是所有小于等于k的情况吗； ((k-1)/m)^n是所有小于k的情况

相减就是k的情况；

## code

```cpp

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    double expected_value = 0.0;

    for (int k = 1; k <= m; ++k) {
        double prob_k = pow((double)k / m, n) - pow((double)(k - 1) / m, n);
        expected_value += k * prob_k;
    }


    printf("%.12f\n", expected_value);

    return 0;
}

```