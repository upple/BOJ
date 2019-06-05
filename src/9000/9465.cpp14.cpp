#include <cstdio>
#define max(x, y) (x>y?x:y)
using namespace std;

int main()
{
	int no_case;
	scanf("%d", &no_case);
	while (no_case--)
	{
		int n;
		long long dp[3][2] = {}, temp = 0;
		scanf("%d", &n);
		long long *score = new long long[n + 2];
		for (int i = 2; i <= n + 1; i++)
			scanf("%lld", &score[i]);

		for (int i = 2; i <= n + 1; i++)
		{
			scanf("%lld", &temp);
			dp[2][1] = max(max(dp[0][0], dp[0][1]), dp[1][0]) + temp;
			dp[2][0] = max(max(dp[0][1], dp[0][0]), dp[1][1]) + score[i];

			dp[0][0] = dp[1][0], dp[0][1] = dp[1][1];
			dp[1][0] = dp[2][0], dp[1][1] = dp[2][1];
		}

		printf("%lld\n", max(max(dp[1][0], dp[1][1]), max(dp[0][0], dp[0][1])));
	}
	return 0;

}