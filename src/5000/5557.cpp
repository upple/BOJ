#include <cstdio>

typedef long long ll;
ll dp[21][101];
int num[101];

ll solve(int n, int k)
{

	if (n == 1)
		return (k == num[1]);

	if (dp[k][n] != -1)
		return dp[k][n];

	dp[k][n] = 0;
	if (k + num[n] <= 20)
		dp[k][n] += solve(n - 1, k + num[n]);

	if (k - num[n] >= 0)
		dp[k][n] += solve(n - 1, k - num[n]);

	return dp[k][n];
}
int main()
{
	int n, k;
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &num[i]);
		for (int j = 0; j <= 20; j++)
			dp[j][i] = -1;

	}

	scanf("%d", &k);
	printf("%lld", solve(n - 1, k));
}