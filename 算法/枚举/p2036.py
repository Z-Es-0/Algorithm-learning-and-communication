def orz(ou,g):
    suan=1;ku=0
    t=False
    for i in range(len(ou)):
        if ou[i]=='1':
            suan*=g[i][0]
            ku+=g[i][1]
            t=True
    if t:return abs(suan-ku)
    else: return 199999999

n=int(input())
g=[]
for _ in range(n):
    s,b=map(int,input().split())
    g.append((s,b))
p=1<<n
ans=199999999

for i in range(p):
    ou=format(i,f'0{n}b')
    da=orz(ou,g)
    if ans>da:
        ans=da
print(ans)


