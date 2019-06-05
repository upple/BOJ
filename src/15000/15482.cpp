#include <cstdio>
#include <cstring>
#define max(x, y) (x>y?x:y)
char s1[3001], s2[3001];
int dp[3001][3001];
int main()
{
	scanf("%s %s", s1, s2);

	for (int i = 0; s2[i]; i+=3)
	{
		for (int j = 0; s1[j]; j+=3)
		{
			if (s1[j] == s2[i] && s1[j+1] == s2[i+1] && s1[j+2] == s2[i+2])
				dp[j + 3][i + 3] = dp[j][i] + 1;

			else
				dp[j + 3][i + 3] = max(dp[j][i + 3], dp[j + 3][i]);
		}

	}

	printf("%d", dp[strlen(s1)][strlen(s2)]);
}