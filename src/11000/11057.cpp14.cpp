#include <cstdio>

using namespace std;

int main()
{
	int n, ans = 0;
	int dp[1001][10] = {};
	scanf("%d", &n);
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k <= j; k++)
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10007;

	for (int i = 0; i <10; i++)
		ans = (ans+dp[n][i]) % 10007;

	printf("%d\n", ans);
	return 0;
}