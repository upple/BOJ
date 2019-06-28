n=int(input())
dp=[0 for _ in range(n+1)]
MOD=int(1e9)
i=1
dp[0]=1
while i<=n:
    for j in range(i, n+1):
        dp[j]=(dp[j]+dp[j-i])%MOD

    i<<=1
print(dp[n])