
#埃拉托斯特尼筛法（Sieve of Eratosthenes）
l=1000001#数据范围
c=[1,1]+[0]*l
for i in range(2,l):
    if 1-c[i]:
        for j in range(i*i,l,i):
            c[j]=1
print(c)#c数组是一个以0表示素数，以1表示非素数的数组

def prime_arr(n=100):#数据范围
    #埃拉托斯特尼筛法（Sieve of Eratosthenes）
    l=n#数据范围
    c=[1,1]+[0]*l
    for i in range(2,l):
        if 1-c[i]:
            for j in range(i*i,l,i):
                c[j]=1
    return c#c数组是一个以0表示素数，以1表示非素数的数组
