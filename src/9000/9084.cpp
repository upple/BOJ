#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m, ans = 0;
		scanf("%d", &n);
		int dp[20][10001] = {};
		int cost[21];

		for (int i = 0; i<n; i++)
			scanf("%d", &cost[i]);

		scanf("%d", &m);
		dp[0][0] = 1;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 0; j<n; j++)
			{
				if (i - cost[j]<0)
					continue;

				for (int s = 0; s <= j; s++)
					dp[j][i] += dp[s][i - cost[j]];
			}
		}

		for (int i = 0; i<n; i++)
			ans += dp[i][m];

		printf("%d\n", ans);

	}
}
