An[i][j]:i->j的路径上所经过的顶点编号不大于k

dpk[i][j]=min(dpk-1[i][j],ak-1[i][k]+ak-1[k][j])

```python
n,e=map(int,input().split())
inf=float('inf')
dp=[[inf for i in range(n+2)] for j in range(n+2)]
for _ in range(e):
    i,j,c=map(int,input().split())
    dp[i][j]=c
for i in range(1,n+1):
    dp[i][i]=0
for k in range(1,n+1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if i!=k and j!=i and j!=k and (dp[i][k]+dp[k][j]<dp[i][j]):
                dp[i][j]=dp[i][k]+dp[k][j]

for i in dp:
    print(i)
```