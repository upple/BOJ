#include <cstdio>

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
bool map[252][252] = {};

void dfs(int x, int y)
{
	map[x][y] = 0;

	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (map[nx][ny])
			dfs(nx, ny);
	}
}

int main()
{
	int n, m, ans = 0;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &map[i][j]);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (map[i][j])
				ans++, dfs(i, j);

	printf("%d", ans);
}