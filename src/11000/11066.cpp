#include <cstdio>
#define INF 99999999

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, dp[501][501], cost[501][501];
		scanf("%d", &n);

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				cost[i][j] = dp[i][j] = INF;

			scanf("%d", &dp[i][i]);
			cost[i][i] = 0;
		}
        
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j + i <= n; j++)
			{
				for (int k = j; k < j + i; k++)
				{
					if (cost[j][j + i] == INF || cost[j][j + i] > dp[j][j + i] + cost[j][k] + cost[k + 1][j + i])
					{
						dp[j][j + i] = dp[j][k] + dp[k + 1][j + i];
						cost[j][j + i] = dp[j][j + i] + cost[j][k] + cost[k + 1][j + i];
					}
				}
			}
		}
        
		printf("%d\n", cost[1][n]);
	}
}