#include <cstdio>

int arr[226], dp[226] = {};
int n, m, k;

int solve(int x)
{
	if (dp[x] || x==1)
		return dp[x];

	if ((x - 1) % m)
		dp[x] += solve(x - 1);

	if (x - m > 0)
		dp[x] += solve(x - m);

	return dp[x];
}
int main()
{
	int ans;
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 1; i <= m*n; i++)
		arr[i] = i;
	if (k)
	{
		int temp;
		dp[k] = 1;
		temp=solve(m*n);
		dp[k] = 0;
		dp[1] = 1;
		ans = solve(k) * temp;
	}
	else
	{
		dp[1] = 1;
		ans = solve(m*n);
	}

	printf("%d", ans);
}