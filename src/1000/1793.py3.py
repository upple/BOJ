dp = [0 for _ in range(251)]
dp[1]=1 
dp[0]=1
for i in range(2, 251):
    dp[i]=dp[i-1]+dp[i-2]*2;
    
while 1:
    try:
        n=int(input())
    except:
        break

    print(dp[n])

