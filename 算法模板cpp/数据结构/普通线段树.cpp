/*
 * @Author: Z-Es-0 141395766+Z-Es-0@users.noreply.github.com
 * @Date: 2024-08-26 22:01:23
 * @LastEditors: Z-Es-0 141395766+Z-Es-0@users.noreply.github.com
 * @LastEditTime: 2024-08-26 22:07:30
 * @FilePath: \Algorithm-learning-and-communication\算法模板cpp\线段树专辑\普通线段树(区间查询\区间修改).cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>

class SegmentTree {
private:
    std::vector<int> tree;
    std::vector<int> arr;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            // 叶子节点将只包含一个元素
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            // 递归构建段树
            build(2*node+1, start, mid);
            build(2*node+2, mid+1, end);
            // 内部节点将包含其两个子节点的和
            tree[node] = tree[2*node+1] + tree[2*node+2];
        }
    }

    void update(int idx, int val, int node, int start, int end) {
        if (start == end) {
            // 叶节点
            arr[start] = val;
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                // 如果 idx 在左子节点中，递归更新左子节点
                update(idx, val, 2*node+1, start, mid);
            } else {
                // 否则递归更新右子节点
                update(idx, val, 2*node+2, mid+1, end);
            }
            // 内部节点将包含其两个子节点的和
            tree[node] = tree[2*node+1] + tree[2*node+2];
        }
    }

    int query(int L, int R, int node, int start, int end) {
        if (R < start || end < L) {
            // 节点代表的范围完全不在给定范围之内
            return 0;
        }
        if (L <= start && end <= R) {
            // 节点代表的范围完全在给定范围之内
            return tree[node];
        }
        // 节点代表的范围部分在给定范围之内
        int mid = (start + end) / 2;
        int left_child_sum = query(L, R, 2*node+1, start, mid);
        int right_child_sum = query(L, R, 2*node+2, mid+1, end);
        return left_child_sum + right_child_sum;
    }

public:
    SegmentTree(std::vector<int>& input) : arr(input) {
        n = input.size();
        tree.resize(4*n);
        build(0, 0, n-1);
    }

    void update(int idx, int val) {
        update(idx, val, 0, 0, n-1);
    }

    int query(int L, int R) {
        return query(L, R, 0, 0, n-1);
    }
};

int main() {
    std::vector<int> input = {1, 3, 5, 7, 9, 11};
    SegmentTree st(input);

    // 输出初始的前五个元素的和
    std::cout << "sum of fiveth " << st.query(0, 4) << std::endl;
    
    // 更新：将索引为2的元素设为10
    st.update(2, 10);

    // 输出更新后的前五个元素的和
    std::cout << "down updata " << st.query(0, 4) << std::endl;

    return 0;
}
