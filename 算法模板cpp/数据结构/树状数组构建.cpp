/*
 * @Author: Z-Es-0 141395766+Z-Es-0@users.noreply.github.com
 * @Date: 2024-08-02 13:17:21
 * @LastEditors: Z-Es-0 141395766+Z-Es-0@users.noreply.github.com
 * @LastEditTime: 2024-08-02 13:17:27
 * @FilePath: \Algorithm-learning-and-communication\算法模板cpp\树状数组构建.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>

class FenwickTree {
private:
    std::vector<int> bit; // 树状数组
    int n;

    // 内部方法，在给定索引更新值
    void add(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx; // 移动到下一个索引
        }
    }

public:
    // 构造函数，初始化树状数组大小
    FenwickTree(int size) {
        this->n = size;
        bit.assign(n + 1, 0); // 初始化树状数组为0
    }

    // 方法：从给定的向量构建树状数组
    void build_tree(const std::vector<int>& s) {
        n = s.size();
        bit.assign(n + 1, 0); // 重置树状数组为新大小

        // 用给定向量的值更新树状数组
        for (int i = 0; i < n; ++i) {
            add(i + 1, s[i]);
        }
    }

    // 方法：获取从1到idx的前缀和
    int prefixSum(int idx) const {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx; // 移动到父节点
        }
        return sum;
    }

    // 方法：获取[left, right]区间的和
    int rangeSum(int left, int right) const {
        return prefixSum(right) - prefixSum(left - 1);
    }

    // 方法：获取索引idx处的原始值（1基索引）
    int pointQuery(int idx) const {
        return rangeSum(idx, idx);
    }

    // 方法：更新树状数组在索引idx处的值
    void update(int idx, int val) {
        add(idx, val);
    }

    // 调试方法：打印树状数组
    void printBIT() const {
        for (int i = 1; i <= n; ++i) {
            std::cout << bit[i] << " ";
        }
        std::cout << std::endl;
    }
};

// 示例使用
int main() {
    // 示例向量
    std::vector<int> s = {1, 2, 3, 4, 5};
    FenwickTree fenwickTree(s.size());

    // 使用向量s构建树状数组
    fenwickTree.build_tree(s);

    // 打印树状数组的内部状态（用于调试）
    std::cout << "构建后的树状数组状态: ";
    fenwickTree.printBIT();

    // 查询区间 [1, 3] 的和
    std::cout << "区间 [1, 3] 的和: " << fenwickTree.rangeSum(1, 3) << std::endl;

    // 更新索引3处的值，增加5
    fenwickTree.update(3, 5);
    std::cout << "索引3更新后的树状数组状态: ";
    fenwickTree.printBIT();

    // 更新后再次查询
    std::cout << "更新后区间 [1, 3] 的和: " << fenwickTree.rangeSum(1, 3) << std::endl;

    return 0;
}
