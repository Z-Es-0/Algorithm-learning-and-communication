[思维/博弈论](https://codeforces.com/group/uWPOOE24k2/contest/1772/problem/E)

## 观察

我们发现如果F和S想要赢分别需要 实现对正序和逆序的排序；那么假设F单独操作，就需要操作所有的 s[i]!=i+1; 同理对于 S就是操作s[i]!=n-i; 

那么我们发现，对于F,S的操作，他们无法对对方照成阻碍，只能为自己操作或者不操作；

## 分别操作阶段

在博弈前期，我们发现 他们只能操作他们需要的数字变成蓝色；而不能不操作或者排序，都是没有意义的操作；

## 博弈阶段

我们发现，有一些操作不但会帮助自己接近可排序，也会帮助对方；那么我们只需要考虑 这个重叠部分

考虑寻找 所有的 s[i]!=i+1；s[i]!=n-i;还有他们的重叠部分；

那么谁先到重叠部分而且在重叠后可以比对方更快的选完重叠部分；就会赢；

如果俩人先后进入了这个重叠部分就会开始不选择防止对方可以排序；就会平局

## code

```python

import math
from queue import Queue
import bisect
import collections
import heapq

def solve():
    n=int(input())
    s=list(map(int,input().split()))
    a=0;b=0;c=0
    for i in range(n):
        if s[i] != i+1 and s[i]!= n-i:
            c+=1
        if s[i]!=i+1:
            a+=1
        if s[i]!=n-i:
            b+=1
    a=n-a
    b=n-b
    if b+c<=a:
        print('First')
    elif a+c<b:
        print('Second')
    else:
        print('Tie')


def main():
    for i in range(int(input())):
        solve()


if __name__ == '__main__':
    main()
    # solve()
```