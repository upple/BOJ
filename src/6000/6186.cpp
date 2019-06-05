#include <cstdio>

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

char map[102][102];
bool visit[101][101];
int r, c, cnt;

void dfs(int x, int y)
{
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (map[nx][ny] == '#' && !visit[nx][ny])
			dfs(nx, ny);
	}
}
int main()
{
	scanf("%d %d", &r, &c);

	for (int i = 1; i <= r; i++)
	{
		scanf("%s", map[i]+1);
	}

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (map[i][j] == '#' && !visit[i][j])
				cnt++, dfs(i, j);
		}
	}

	printf("%d", cnt);
}