#include <cstdio>
#include <cstring>
#include <algorithm>
char s1[1001], s2[1001];
char ans[1001];
int dp[1001][1001], p[1001];

int main()
{
	scanf("%s %s", s1, s2);
	int size1 = strlen(s1), size2 = strlen(s2);
	for (int i = 0; s2[i]; i++)
	{
		for (int j = 0; s1[j]; j++)
		{
			if (s1[j] == s2[i])
				dp[j + 1][i + 1] = dp[j][i] + 1;

			else
				dp[j + 1][i + 1] = std::max(dp[j][i + 1], dp[j + 1][i]);

		}

	}

	int i = size2, j = size1, cur=dp[j][i];
	while (dp[j][i])
	{
		if (cur == dp[j][i - 1])
			i--;

		else if (cur == dp[j - 1][i])
			j--;

		else
		{
			ans[cur - 1] = s1[j - 1];
			i--, j--, cur = dp[j][i];
		}
	}

	printf("%d\n%s", dp[strlen(s1)][strlen(s2)], ans);
}