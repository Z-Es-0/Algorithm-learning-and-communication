#include <iostream>
#include <vector>
#define lowbit(x) (x & (-x))
using namespace std;

class FenwickTree {
private:
    vector<int> tree;
    vector<int> original;
    int n;
    // 构建树状数组
    vector<int> buildTree(const vector<int>& s) {
        vector<int> tree(n + 1, 0);
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            int x = i + 1;
            prefixSum[x] = prefixSum[x - 1] + s[i];
            tree[x] = prefixSum[x] - prefixSum[x - lowbit(x)];
        }
        return tree;
    }

    // 计算前缀和
    int findPrefixSum(int x) const {
        int sum = 0;
        while (x != 0) {
            sum += tree[x];
            x -= lowbit(x);
        }
        return sum;
    }

public:
    // 构造函数
    FenwickTree(const vector<int>& s) {
        n = s.size();
        original = s;
        vector<int> g;
        int last = 0;

        // 构造差分数组
        for (int si : s) {
            g.push_back(si - last);
            last = si;
        }

        // 初始化树状数组
        tree = buildTree(g);
    }

    // 单点增加操作
    void addOne(int x, int i) {
        while (i < tree.size()) {
            tree[i] += x;
            i += lowbit(i);
        }
    }

    // 区间更新：在区间 [x, y] 增加 k
    void rangeUpdate(int x, int y, int k) {
        addOne(k, x);
        addOne(-k, y + 1);
    }

    // 单点查询
    int pointQuery(int x) const {
        return findPrefixSum(x);
    }

    // 区间和查询
    int rangeQuery(int l, int r) const {
        return findPrefixSum(r) - findPrefixSum(l - 1);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> s(n);
    for (int& si : s) cin >> si;

    // 创建树状数组对象
    FenwickTree fenwick(s);

    // 处理操作
    for (int i = 0; i < m; ++i) {
        int a, x;
        cin >> a >> x;
        if (a == 1) {
            int y, k;
            cin >> y >> k;
            fenwick.rangeUpdate(x, y, k);
        } else {
            cout << fenwick.pointQuery(x) << endl;
        }
    }
    return 0;
}
