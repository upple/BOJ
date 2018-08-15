dp = [[0 for _ in range(101)] for _ in range(101)]

def solve(n, m):
    if dp[n][m]: return dp[n][m]
    if m==0 or n==m: return 1
    dp[n][m]=solve(n-1, m-1)+solve(n-1, m)
    return dp[n][m]

n, m=map(int, input().split())
print(solve(n, m))