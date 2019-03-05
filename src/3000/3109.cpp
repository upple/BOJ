#include <cstdio>

int r, c;
char map[10000][501];

int dfs(int x, int y)
{
	map[x][y] = 'x';
	if (y == c - 1)
		return 1;

	for (int i = -1; i <= 1; i++)
	{
		int nx = x + i, ny = y + 1;
		if (nx < 0 || nx >= r || map[nx][ny] == 'x')
			continue;

		if (dfs(nx, ny))
			return 1;
	}

	return 0;
}
int main()
{
	int ans = 0;
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++)
	{
		scanf("%s", map[i]);
	}

	for (int i = 0; i < r; i++)
	{
		if (map[i][0] == '.')
		{
			ans += dfs(i, 0);
		}
	}

	printf("%d", ans);
}