#include <iostream>
#include <vector>

using namespace std;

// 线段树类，支持区间加法和区间求和
class SegmentTree {
private:
    vector<long long> tree;  // 线段树的数组
    vector<long long> lazy;  // 延迟标记数组，存储区间的延迟更新
    int n;                   // 数组的大小

    // 建树函数，初始化线段树
    void build(const vector<int> &arr, int node, int start, int end) {
        if (start == end) {
            // 叶节点，直接存储数组中的值
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            // 递归构建左子树
            build(arr, 2 * node + 1, start, mid);
            // 递归构建右子树
            build(arr, 2 * node + 2, mid + 1, end);
            // 当前节点存储左右子树的和
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    // 下推延迟标记，处理区间更新的延迟操作
    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
            // 当前节点的值需要增加 lazy[node] * 区间长度
            tree[node] += lazy[node] * (end - start + 1);
            if (start != end) {
                // 如果不是叶节点，将延迟标记传递给子节点
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            // 清空当前节点的延迟标记
            lazy[node] = 0;
        }
    }

    // 区间加法更新 [L, R] 加上 k
    void update_range(int node, int start, int end, int L, int R, int k) {
        // 先处理当前节点的延迟标记
        propagate(node, start, end);

        if (start > R || end < L) {
            // 完全不相交，直接返回
            return;
        }

        if (start >= L && end <= R) {
            // 当前节点完全在 [L, R] 范围内，延迟标记更新
            tree[node] += k * (end - start + 1);
            if (start != end) {
                // 传递更新给左右子节点
                lazy[2 * node + 1] += k;
                lazy[2 * node + 2] += k;
            }
            return;
        }

        // 递归更新左右子树
        int mid = (start + end) / 2;
        update_range(2 * node + 1, start, mid, L, R, k);
        update_range(2 * node + 2, mid + 1, end, L, R, k);
        // 更新当前节点的值
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    // 区间求和查询 [L, R]
    long long query_range(int node, int start, int end, int L, int R) {
        // 先处理当前节点的延迟标记
        propagate(node, start, end);

        if (start > R || end < L) {
            // 完全不相交，返回 0
            return 0;
        }

        if (start >= L && end <= R) {
            // 当前节点完全在 [L, R] 范围内，返回其值
            return tree[node];
        }

        // 递归查询左右子树
        int mid = (start + end) / 2;
        long long left_sum = query_range(2 * node + 1, start, mid, L, R);
        long long right_sum = query_range(2 * node + 2, mid + 1, end, L, R);
        // 返回左右子树的和
        return left_sum + right_sum;
    }

public:
    // 构造函数，初始化线段树和延迟数组
    SegmentTree(const vector<int> &arr) {
        n = arr.size();
        tree.resize(4 * n);
        lazy.resize(4 * n, 0);
        build(arr, 0, 0, n - 1);
    }

    // 更新区间 [L, R]，每个数加上 k
    void update(int L, int R, int k) {
        update_range(0, 0, n - 1, L, R, k);
    }

    // 查询区间 [L, R] 的和
    long long query(int L, int R) {
        return query_range(0, 0, n - 1, L, R);
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 创建线段树
    SegmentTree segtree(arr);

    // 处理 m 个操作
    for (int i = 0; i < m; i++) {
        int op;
        cin >> op;

        if (op == 1) {
            // 操作 1：将区间 [x, y] 加上 k
            int x, y, k;
            cin >> x >> y >> k;
            // 将 x, y 转换为 0 基索引
            segtree.update(x - 1, y - 1, k);
        } else if (op == 2) {
            // 操作 2：查询区间 [x, y] 的和
            int x, y;
            cin >> x >> y;
            // 将 x, y 转换为 0 基索引
            cout << segtree.query(x - 1, y - 1) << endl;
        }
    }

    return 0;
}
