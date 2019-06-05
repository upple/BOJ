#include <cstdio>
#include <algorithm>
int dp[1000001];
int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		dp[x] = std::max(dp[x], dp[x - 1] + 1);
		ans = std::max(ans, dp[x]);
	}
	printf("%d", ans);
}