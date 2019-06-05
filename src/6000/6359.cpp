#include <cstdio>

int main()
{
	bool arr[101] = {};
	int dp[101] = {};
	for (int i = 1; i <= 100; i++)
	{
		int temp = i;
		for (; temp <= 100; temp += i)
			arr[temp] = !arr[temp];

		dp[i] = dp[i - 1] + arr[i];
	}
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", dp[n]);		
	}
}