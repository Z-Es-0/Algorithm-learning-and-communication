#define lowbit(x) (x & -x)
#define N 200005
#define MOD 1000000007
int t, p;


int bit[N];//数的最大值，如果太大还得离散化

void update(int index, int value) {
    while (index < N) {
        bit[index] += value;
        index += lowbit(index);
    }
}

int query(int index) {
    int sum = 0;
    while (index > 0) {
        sum += bit[index];
        index -= lowbit(index);
    }
    return sum;
}

int countInversions(vector<int>& arr) {
    int n = arr.size();
    int invCount = 0;
 
    memset(bit, 0, sizeof(bit));
    for (int i = n - 1; i >= 0; --i) {
        invCount += query(arr[i] - 1);
        update(arr[i], 1);
    }
    return invCount;
}