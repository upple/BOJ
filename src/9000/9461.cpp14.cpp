#include <cstdio>
using namespace std;

int main()
{
	long long dp[101]={};
	int t, n;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		dp[1]=dp[2]=dp[3]=1, dp[4]=2;
		for(int i=5; i<=n; i++)
			dp[i]=dp[i-5]+dp[i-1];

		printf("%lld\n", dp[n]);
	}
	return 0;
}
