def memoize(func):#记忆化搜索装饰器
    memo = {}
    def helper(n, m):
        if (n, m) not in memo:
            memo[(n, m)] = func(n, m)
        return memo[(n, m)]
    return helper

@memoize
def C(n, m):#计算组合数
    if n == m or m == 0:
        return 1
    return C(n-1, m-1) + C(n-1, m)



if __name__ == '__main__':
    n,m=map(int,input().split())
    print(C(n,m))