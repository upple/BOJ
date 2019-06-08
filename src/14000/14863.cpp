#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int map[2][2][101];  // w/r, t/m, n
int dp[100001][101];
int v[100001][101];
int solve(int n, int k)
{
	if (k < 0)
		return 0;

	if (v[k][n])
		return dp[k][n];

	if (n == 0)
	{
		if (k >= map[0][0][0])
			dp[k][n] = max(dp[k][n], map[0][1][0]);

		if (k >= map[1][0][0])
			dp[k][n] = max(dp[k][n], map[1][1][0]);

		v[k][n] = 1;

		return dp[k][n];
	}

	for (int i = 0; i < 2; i++)
	{
		int tmp = solve(n - 1, k - map[i][0][n]);
		dp[k][n] = max(dp[k][n], max(solve(n, k - 1), tmp == 0 ? 0 : map[i][1][n] + tmp));
	}

	v[k][n] = 1;
	return dp[k][n];
}
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
		scanf("%d %d %d %d", &map[0][0][i], &map[0][1][i], &map[1][0][i], &map[1][1][i]);

	int ans = solve(n - 1, k);

	printf("%d", ans);
}