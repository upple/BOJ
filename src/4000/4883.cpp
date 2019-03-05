#include<cstdio>
#include<vector>
#define min(x, y) (x<y?x:y)
using namespace std;
int main()
{
	int n, test_case=0;
	while (++test_case)
	{
		scanf("%d", &n);
		if (n == 0)
			break;

		vector<vector<int> > dp(n + 1, vector<int>(3, 0));

		for (int i = 1; i <= n; i++)
			scanf("%d %d %d", &dp[i][0], &dp[i][1], &dp[i][2]);

		dp[1][0] = dp[1][1] + 1;
		dp[1][2] += dp[1][1];

		for (int i = 2; i <= n; i++)
		{
			dp[i][0] += min(dp[i - 1][0], dp[i - 1][1]);
			dp[i][1] += min(min(dp[i - 1][0], dp[i - 1][1]), min(dp[i - 1][2], dp[i][0]));
			dp[i][2] += min(min(dp[i - 1][1], dp[i - 1][2]), dp[i][1]);
		}

		printf("%d. %d\n", test_case, dp[n][1]);
	}
}