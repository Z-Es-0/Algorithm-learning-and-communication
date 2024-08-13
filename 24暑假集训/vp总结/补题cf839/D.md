<!--
 * @Author: Z-Es-0 141395766+Z-Es-0@users.noreply.github.com
 * @Date: 2024-08-11 11:30:45
 * @LastEditors: Z-Es-0 141395766+Z-Es-0@users.noreply.github.com
 * @LastEditTime: 2024-08-11 11:45:06
 * @FilePath: \Algorithm-learning-and-communication\24暑假集训\vp总结\补题cf839\D.md
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
[好难的数学](https://codeforces.com/group/uWPOOE24k2/contest/1772/problem/D)

## 不会

我们维护一个可行解的区间



我们只推数学能推出柿子：

对于一个s[i]:

abs(x-s[i])<= abs(x-s[i+1]);

两边平方(高中生秒了)；

x^2 - 2*x*s[i] +s[i]^2 <= x^2 - 2*x*s[i+1]+s[i+1]^2

变形

2(a[i+1]−a [i])x≤(a [i+1]−a [i])(a[i+1]+a[i] )

分情况讨论

a[i]< a[i+1] : x<= (a[i+1]+a[i])/2

a[i]>a[i+1]: x>= (a[i+1]+a[i]+1)/2

维护左右边界即可

## code

```python


import math
from queue import Queue
import bisect
import collections
import heapq

def check(k,s):
    re =[ ]
    for i in s:
        re.append(abs(k-i))
    return re == sorted(re)
def solve():
    n=int(input())
    s=list(map(int,input().split()))
    if s == sorted(s):
        print(0)
    elif s == sorted(s,reverse=True):
        print(s[0])
    else:
        l=0
        r=10000009
        for i in range(n-1):
            if (s[i]<s[i+1]): r =min(r,(s[i]+s[i+1])//2)
            if (s[i]>s[i+1]): l =max(l,(s[i]+s[i+1]+1)//2)
        if check(l,s):
            print(l)
        else:
            print(-1)
def main():
    for i in range(int(input())):
        solve()


if __name__ == '__main__':
    main()
    # solve()
```