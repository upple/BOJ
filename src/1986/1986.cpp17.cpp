#include <cstdio>

int n, m;
char map[1001][1001];

void setQ(int x, int y)
{
	int dx[] = { 1, 1, -1, -1, 0, 1, 0, -1 };
	int dy[] = { 1, -1, 1, -1, 1, 0, -1, 0 };
	for (int i = 8; i--;)
	{
		int nx = x, ny = y;
		while (1)
		{
			nx += dx[i], ny += dy[i];
			if (nx <= 0 || nx > n || ny <= 0 || ny > m || map[nx][ny] > 1) break;
			map[nx][ny] = 1;
		}
	}
}
void setK(int x, int y)
{
	int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	int dy[] = { 2, 1, -1, -2, -2, -1, 1, 2 };

	for (int i = 8; i--;)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (nx <= 0 || nx > n || ny <= 0 || ny > m || map[nx][ny]) continue;
		map[nx][ny] = 1;
	}
}

int main()
{
	scanf("%d %d", &n, &m);

	int q, k, p;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		map[x][y] = 2;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		map[x][y] = 3;
	}
	scanf("%d", &p);
	for (int i = 0; i < p; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		map[x][y] = 4;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			switch (map[i][j])
			{
			case 2: setQ(i, j); break;
			case 3: setK(i, j); break;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			ans += (map[i][j] == 0);

	printf("%d", ans);
}