/*
 *                   ___====-_  _-====___
 *             _--^^^#####//      \\#####^^^--_
 *          _-^##########// (    ) \\##########^-_
 *         -############//  |\^^/|  \\############-
 *       _/############//   (@::@)   \############\_
 *      /#############((     \\//     ))#############\
 *     -###############\\    (oo)    //###############-
 *    -#################\\  / VV \  //#################-
 *   -###################\\/      \//###################-
 *  _#/|##########/\######(   /\   )######/\##########|\#_
 *  |/ |#/\#/\#/\/  \#/\##\  |  |  /##/\#/  \/\#/\#/\#| \|
 *  `  |/  V  V  `   V  \#\| |  | |/#/  V   '  V  V  \|  '
 *     `   `  `      `   / | |  | | \   '      '  '   '
 *                      (  | |  | |  )
 *                     __\ | |  | | /__
 *                    (vvv(VVV)(VVV)vvv)
 * 
 *      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 
 *                神兽保佑            永无BUG
 */

/*
 * @Author: Z-Es-0 141395766+Z-Es-0@users.noreply.github.com
 * @Date: 2024-08-02 12:59:04
 * @LastEditors: Z-Es-0 141395766+Z-Es-0@users.noreply.github.com
 * @LastEditTime: 2024-08-02 12:59:12
 * @FilePath: \Algorithm-learning-and-communication\算法模板cpp\树状数组区间修改单点查询.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define lowbit(x) x&(-x)
#define N 200005
#define M 1005
#define MOD 1000000007

int t;

class FenwickTree {
private:
    std::vector<int> tree;
    int n;

    // 内部函数，用于在index位置增加value
    void add(int index, int value) {
        while (index <= n) {
            tree[index] += value;
            index += index & -index; // 前进到下一个节点
        }
    }

public:
    // 构造函数，初始化树状数组
    FenwickTree(int size) : n(size), tree(size + 1, 0) {}

    // 区间增加 [left, right] 加上value
    void rangeAdd(int left, int right, int value) {
        add(left, value);
        add(right + 1, -value);
    }

    // 单点查询：查询位置index的值
    int pointQuery(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index; // 回退到上一个节点
        }
        return sum;
    }
};