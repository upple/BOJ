#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n, arr[100000], dp[2][100000], ans=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	if (n == 1)
	{
		printf("%d", arr[0]);
		return 0;
	}

	dp[0][0] = arr[0], dp[0][1] = max(arr[0] + arr[1], arr[1]);
	dp[1][0] = 0; dp[1][1] = max(arr[0], arr[1]);
	ans = max(dp[0][1], dp[1][1]);
	for (int i = 2; i < n; i++)
	{
		dp[0][i] = max(dp[0][i - 1] + arr[i], arr[i]);
		dp[1][i] = max(max(dp[1][i - 1], dp[0][i - 2]) + arr[i], dp[0][i - 1]);
		ans = max(max(dp[0][i], dp[1][i]), ans);
	}

	printf("%d", ans);
}