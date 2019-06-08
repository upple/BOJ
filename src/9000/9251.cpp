#include <cstdio>
#include <cstring>
#define max(x, y) (x>y?x:y)
int main()
{
	char s1[1001], s2[1001];
	int dp[1001][1001] = {};
	scanf("%s %s", s1, s2);

	for (int i = 0; s2[i]; i++)
	{
		for (int j = 0; s1[j]; j++)
		{
			if (s1[j] == s2[i])
				dp[j + 1][i + 1] = dp[j][i] + 1;

			else
				dp[j + 1][i + 1] = max(dp[j][i + 1], dp[j + 1][i]);
		}

	}

	printf("%d", dp[strlen(s1)][strlen(s2)]);
}