t=int(input())

while t:
    t-=1
    n=int(input())
    arr=[]
    arr.append(list(map(int, input().split())))
    arr.append(list(map(int, input().split())))

    dp=[[0 for i in range(n)]for j in range(2)]
    dp[0][0]=arr[0][0]
    dp[1][0]=arr[1][0]
    dp[1][1]=dp[0][0]+arr[1][1]
    dp[0][1]=dp[1][0]+arr[0][1]

    for i in range(2, n):
        for j in [True, False]:
            dp[j][i]=max(dp[not j][i-1], dp[j][i-2], dp[not j][i-2])+arr[j][i]

    print(max(dp[0][n-1], dp[1][n-1]))

