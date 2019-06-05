#include <cstdio>
#include <algorithm>
using namespace std;
int dp[1001], arr[1001];
int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int l = 99999999, r = 0;
		scanf("%d", &arr[i]);
		for (int j = i; j >= 0; j--)
		{
			l = min(l, arr[j]);
			r = max(r, arr[j]);
			dp[i] = max(dp[i], dp[j - 1] + r - l);
		}
	}

	printf("%d", dp[n-1]);
}