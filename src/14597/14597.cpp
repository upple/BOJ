#include <cstdio>
#include <algorithm>
using namespace std;

int arr[101][102];
int dp[101][102];
int h, w;

int main()
{

	scanf("%d %d", &h, &w);

	for (int i = 1; i <= h+1; i++)
		for (int j = 0; j <= w+1; j++)
			dp[i][j] = 99999999;

	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			scanf("%d", &arr[i][j]);

	int tmp;
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			scanf("%d", &tmp);
			arr[i][j] -= tmp;
			arr[i][j] = arr[i][j] * arr[i][j];
		}
	}

	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i - 1][j + 1]) + arr[i][j];

	int ans = 99999999;
	for (int i = 1; i <= w; i++)
		ans = min(ans, dp[h][i]);

	printf("%d", ans);
}