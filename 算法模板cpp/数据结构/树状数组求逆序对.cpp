/*
 * @Author: Z-Es-0 zes18642300628@qq.com
 * @Date: 2024-07-26 15:03:19
 * @LastEditors: Z-Es-0 zes18642300628@qq.com
 * @LastEditTime: 2024-10-03 15:07:49
 * @FilePath: \Algorithm-learning-and-communication\算法模板cpp\数据结构\树状数组求逆序对.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


#define lowbit(x) (x & -x)
#define N 200005
#define MOD 1000000007
int t, p;


int bit[N];//数的最大值，如果太大还得离散化

//通用型离散化技巧： 对于值过大，数组数量可以接受的情况：我们可以排序后按值->索引的形式离散化，操作索引序列即可；

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

int reverse_pair(vector<int>& arr) {
    int n = arr.size();
    int invCount = 0;
 
    memset(bit, 0, sizeof(bit));
    for (int i = n - 1; i >= 0; --i) {
        invCount += query(arr[i] - 1);
        update(arr[i], 1);
    }
    return invCount;
}

// 注意： 数组数组只能处理正整数； 