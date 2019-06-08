#include<cstdio>
using namespace std;

int solution(int n, int k)
{
	if (k==0)
		k = n - k;
	int dp[1001][1001] = {};
	dp[1][1] = dp[1][0] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i - 1][0] = 1;
		for (int j = 1; j <= i; j++)
			dp[i][j] = (dp[i-1][j - 1] + dp[i-1][j])%10007;

	}

	return dp[n][k];
}
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	printf("%d", solution(n, k));
}