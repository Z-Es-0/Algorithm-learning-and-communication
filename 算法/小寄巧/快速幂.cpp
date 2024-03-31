#include <iostream>
#include <vector>
#define int long long
using namespace std;

int qpow(int a, int n)//快速幂
{
    if (n == 0)
        return 1;
    else if (n % 2 == 1)
        return qpow(a, n - 1) * a;
    else
    {
        int temp = qpow(a, n / 2);
        return temp * temp;
    }
}
signed main(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<a<<'^'<<b<<" mod "<<c<<'='<<qpow(a,b)<<endl;
}