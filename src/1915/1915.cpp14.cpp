#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int dp[1001][1001] = {};
	char ch[1002];
	int n, m, ans=0;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		scanf("%s", ch + 1);
		for (int j = 1; j <= m; j++)
		{
			if (ch[j] == '1')
				dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1])+1;

			ans = max(ans, dp[i][j]);
		}
	}

	printf("%d", ans*ans);
}