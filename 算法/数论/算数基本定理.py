def prime_factors(n):
    '''算数基本定理:一个整数n可以被拆分成素数的乘积
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
