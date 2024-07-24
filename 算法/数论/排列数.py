def perm(n, m):
    res = 1
    for i in range(n, n - m, -1):
        res *= i
    return res

n, m = map(int, input().strip().split())
print(perm(n, m))
