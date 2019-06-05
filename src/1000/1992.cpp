#include <cstdio>

int n;
char adj[66][66];
void solve(int x, int y, int size)
{
	char color = adj[x][y];
	int half = size / 2;
	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (adj[i][j] != color)
			{
				printf("(");
				solve(x, y, half), solve(x, y + half, half);
				solve(x + half, y, half), solve(x + half, y + half, half);
				printf(")");
				return;
			}
		}
	}

	printf("%c", color);
}

int main()
{
	scanf("%d",&n);

	for (int i = 1; i <= n; i++)
		scanf("%s", (adj[i] + 1));

	solve(1, 1, n);
}