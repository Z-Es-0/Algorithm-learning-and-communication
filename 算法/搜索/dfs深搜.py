'''全排列问题：

按照字典序输出自然数 1 到 n 所有不重复的排列，即 n 的全排列，要求所产生的任一数字序列中不允许出现重复的数字。

输入格式
一个整数 n

输出格式：

 组成的所有不重复的数字序列，每行一个序列。'''


def dfs(u,a,st,n):
    if u==n+1:
        for i in range(1,n+1):
            print(f"{a[i]:>5d}",end='')
        print()
        return
    for i in range(1,n+1):
        if not st[i]:
            a[u]=i
            st[i]=True
            dfs(u+1,a,st,n)
            st[i]=False

if __name__ == '__main__':
    n=int(input())
    st = [False for _ in range(n + 1)]
    a = [0 for _ in range(n + 1)]
    dfs(1,a,st,n)