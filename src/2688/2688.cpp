#include <cstdio>
#include <algorithm>
using namespace std;

long long dp[65][10];
int main()
{
	int n, ans = 0;
	for (int i = 0; i < 10; i++)
		dp[0][i] = 1;

	for (int i = 1; i <= 64; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k <= j; k++)
				dp[i][j] = (dp[i][j] + dp[i - 1][k]);

	int t;
	scanf("%d", &t);

	while (t--)
	{
		scanf("%d", &n);
		printf("%lld\n", *max_element(dp[n], dp[n] + 10));
	}

}