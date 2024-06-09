def EulerSieve(n):  # n为筛选的范围上限
    prime = []  # 用于存储找到的素数
    is_prime = [True] * (n + 1)  # 初始化标记数组，假设所有数都是素数
    for i in range(2, n + 1):
        if is_prime[i]:  # 如果i是素数
            prime.append(i)  # 将i添加到素数列表
        for p in prime:
            if i * p > n:  # 如果超过了筛选范围，就退出循环
                break
            is_prime[i * p] = False  # 标记合数
            if i % p == 0:  # 关键步骤：保证了每个合数只会被其最小的素因子筛除
                break
    return prime

n = 1000
lis = EulerSieve(n)
for i in lis:
    print(i, end = ' ')