#include <cstdio>
#define min(x, y) (x<y?x:y)
#define INF 9999999
int main()
{
	int n, arr[1000], dp[1000] = {};
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]), dp[i] = INF;

	dp[0] = 0;
	for (int i = 0; i < n; i++)
	{
		if (dp[i] == INF)
			continue;

		for (int j = i + 1; j <= i + arr[i] && j < n; j++)
			dp[j] = min(dp[i] + 1, dp[j]);
			
	}

	printf("%d", (dp[n - 1] == INF ? -1 : dp[n - 1]));
}