#include <cstdio>

int test[3][101];
int player[200][3];
int n;
int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int *cur = player[i];
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", cur);
			test[j][*cur]++;
			cur++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		int score = 0;
		for (int j = 0; j < 3; j++)
		{
			if (test[j][player[i][j]] == 1)
				score += player[i][j];
		}

		printf("%d\n", score);
	}
}