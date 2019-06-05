#include <cstdio>
#include <vector>
#define max(x, y) (x>y?x:y)
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> dp(n+1);
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &dp[i]);
		for (int j = 1; j <= i; j++)
		{
			dp[i] = max(dp[i - j] + dp[j], dp[i]);
		}

	}
	printf("%d\n", dp[n]);
	return 0;
}