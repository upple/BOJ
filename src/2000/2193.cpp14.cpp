#include <cstdio>

using namespace std;

int main()
{
	int n;
	long long ans = 0, dp[91][2] = {};
	scanf("%d", &n);

	dp[1][0] = 0;
	dp[1][1] = 1;

	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	ans = dp[n][0] + dp[n][1];
	printf("%lld\n", ans);
	return 0;
}