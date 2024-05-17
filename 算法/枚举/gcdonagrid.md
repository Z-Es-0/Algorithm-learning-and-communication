[GCD on a grid](https://codeforces.com/contest/1955/problem/G)


gcd(a,b)是最大的a,b的公共因子；对于其他的a,b的公共因子一定是gcd(a,b)的因子；

所以枚举gcd(a,b)的因子；然后用dp做check
