'''将各个常用数论相关函数或数据结构放入该包中'''


def prime_arr(n=100):#数据范围
    '''埃拉托斯特尼筛法（Sieve of Eratosthenes）
    通过该算法可以快速得到真假素数列表'''
    l=n#数据范围
    c=[1,1]+[0]*l
    for i in range(2,l):
        if 1-c[i]:
            for j in range(i*i,l,i):
                c[j]=1
    return c   #c数组是一个以0表示素数，以1表示非素数的数组


def prime_factors(n):
    '''算数基本定理
    参数n，返回值为将n拆分的数组
    即该数组的乘积等于n'''
    factors = []
    divisor = 2
    while divisor <= n:
        if n % divisor == 0:
            factors.append(divisor)
            n = n // divisor
        else:
            divisor += 1

    return factors#返回值为数组


def kadane(arr):
    """
    使用Kadane算法计算给定数组中最大子数组和。
    :param arr: 输入的整数数组
    :return: 数组中最大子数组的和
    """
    if not arr:
        return 0
    cmax = gmax = arr[0]
    for i in range(1, len(arr)):
        cmax = max(arr[i], cmax + arr[i])
        gmax = max(gmax, cmax)
    return gmax



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


def gcd(a, b):#最大公约数
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):#最小公倍数
    return a * b // gcd(a, b)