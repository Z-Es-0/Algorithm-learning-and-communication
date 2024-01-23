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
