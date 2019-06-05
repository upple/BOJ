#include <cstdio>

typedef long long ll;

ll adj[100][100], dp[100][100] = {};
int n;

ll ans(int x, int y)
{
	if (dp[x][y] != -1)
		return dp[x][y];

	dp[x][y] = 0;
	for (int i = x-1; i >= 0; i--)
		if (i + adj[i][y] == x)
			dp[x][y] += ans(i, y);

	for (int i = y-1; i >= 0; i--)
		if (i + adj[x][i] == y)
			dp[x][y] += ans(x, i);

	return dp[x][y];
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%lld", &adj[i][j]), dp[i][j]=-1;

	dp[0][0] = 1;
	printf("%lld", ans(n - 1, n - 1));
}