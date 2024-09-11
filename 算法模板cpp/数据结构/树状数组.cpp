#include <bits/stdc++.h>
//using namespace std;
//#define int long long
#define lowbit(x) (x & (-x))
#define N 100005
#define MOD (1e9+7)
int t,n;

class FenwickTree {
private:
    std::vector<int> bit;
    int n;

    // 内部函数：计算前缀和，从1到idx
    int prefixSum(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx; // 移动到父节点
        }
        return sum;
    }

public:
    // 构造函数：初始化树状数组，大小为size
    FenwickTree(int size) {
        this->n = size;
        bit.assign(n + 1, 0); // 初始化BIT，所有元素设为0
    }

    // 单点更新函数：在索引idx处增加值val
    void update(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx; // 移动到下一个相关节点
        }
    }

    // 区间查询函数：查询[left, right]区间的和
    int rangeQuery(int left, int right) {
        return prefixSum(right) - prefixSum(left - 1);
    }

    // 查询特定索引的值：实际上是查询[idx, idx]区间的和
    int query(int idx) {
        return rangeQuery(idx, idx);
    }

    // 打印树状数组（用于调试）
    void print() {
        for (int i = 1; i <= n; ++i) {
            std::cout << bit[i] << " ";
        }
        std::cout << std::endl;
    }
};