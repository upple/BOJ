#include <cstdio>

int main()
{
	bool dp[2000][2000] = {};
	int arr[2000];
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < n; i++)
	{
		dp[i][i] = 1;
		for (int j = 1; i + j < n && i - j >= 0; j++)
		{
			if (arr[i + j] == arr[i - j])
				dp[i - j][i + j] = 1;

			else
				break;
		}
		for (int j = 0; i + j + 1 < n && i - j >= 0; j++)
		{
			if (arr[i + j + 1] == arr[i - j])
				dp[i - j][i + j + 1] = 1;

			else
				break;
		}
	}

	scanf("%d", &m);
	while (m--)
	{
		register int s, e;
		scanf("%d %d", &s, &e);
		
		printf("%d\n", dp[s-1][e-1]);
	}
	

}