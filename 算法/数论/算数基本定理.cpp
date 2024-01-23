#include <iostream>
using namespace std;
int* prime_factors(int x, int& size) {//算数基本定理参数int x,size作为返回数组的长度

    int* a = new int[x];  // 使用 new 动态分配数组
    int cnt = 0;

    for (int i = 2; i <= x / i; i++) {
        while (x % i == 0) {
            a[cnt++] = i;
            x /= i;
        }
    }

    if (x > 1) {
        a[cnt++] = x;
    }

    size = cnt;  // 将数组大小传递给调用者

    return a;  // 返回指向动态分配数组的指针
}
//在函数外可用size作为数组长度.

int main() {
    int n ;
    int size;
    cin>>n;

    // 调用函数并获取返回的数组指针和大小
    int* factors = prime_factors(n, size);

    // 打印返回的数组元素
    for (int i = 0; i < size; ++i) {
        std::cout << factors[i] << " ";
    }

    // 记得释放动态分配的内存
    delete[] factors;

    return 0;
}