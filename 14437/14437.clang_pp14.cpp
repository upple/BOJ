#include <cstdio>
#define MOD 1000000007 

int main()
{
	int d[3001][3001] = {};
	int s, len;
	char str[3001];

	scanf("%d %s", &s, str);
	for (len = 0; str[len]; len++);

	for (int i = 0; i <= len; i++)
		d[i][0] = 1;

	for (int i = 0; i <= 25; i++)
		d[1][i] = 1;



	for (int i = 2; i <= len; i++)
	{
		for (int j = 1; j <= s; j++)
		{
			if (j >= 26)
				d[i][j] = ((d[i - 1][j] + d[i][j - 1]) % MOD - d[i - 1][j - 26] + MOD) % MOD;

			else
				d[i][j] = (d[i - 1][j] + d[i][j - 1]) % MOD;

		}
	}

	printf("%d", d[len][s]);

}