#include <cstdio>

const long long MOD=1000000007;
int dp[1000001];
int main()
{
	long long n, m, k, sum=1;
	scanf("%lld%lld%lld", &n, &m, &k);

	dp[0]=1;
	for(int i=1; i<k; i++)
	{
		dp[i]=(dp[i-1]*m)%MOD;
		sum=(sum*m)%MOD;
	}

	sum=(sum*m)%MOD;
	dp[k]=(MOD+sum-m)%MOD;
	for(int i=k+1; i<=n; i++)
	{
		sum=(sum*m)%MOD;
		dp[i]=(MOD*MOD+dp[i-1]*m-dp[i-k]*(m-1))%MOD;
	}

	printf("%d", int((MOD+sum-dp[n])%MOD));
}