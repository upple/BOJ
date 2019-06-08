#include <cstdio>
#include <queue>
#include <algorithm>
#define INF 9999999
using namespace std;
struct xyd { int x, y, d; };
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
char map[52][52];
int dist[51][51][4];
bool ck;
int sx, sy, ex, ey;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", map[i] + 1);
		for (int j = 1; j <= n; j++)
		{
			for (int k = 0; k < 4; k++)
				dist[i][j][k] = INF;

			if (map[i][j] == '#')
			{
				if (!ck)
					sx = i, sy = j, ck = 1;

				else
					ex = i, ey = j;

				map[i][j] = '.';
			}
		}
	}

	queue<xyd> Q;
	for (int i = 0; i < 4; i++)
		Q.push({ sx, sy, i }), dist[sx][sy][i] = 0;

	while (Q.size())
	{
		int x = Q.front().x, y = Q.front().y, d = Q.front().d;
		Q.pop();

		int nx = x + dx[d], ny = y + dy[d];
		if (map[nx][ny] != '*' && dist[nx][ny][d] > dist[x][y][d])
		{
			dist[nx][ny][d] = dist[x][y][d];
			Q.push({ nx, ny, d });
		}

		if (map[nx][ny] == '!')
		{
			if (dist[nx][ny][(d + 1) % 4] > dist[x][y][d] + 1)
			{
				dist[nx][ny][(d + 1) % 4] = dist[x][y][d] + 1;
				Q.push({ nx, ny, (d + 1) % 4 });
			}
			if (dist[nx][ny][(d + 3) % 4] > dist[x][y][d] + 1)
			{
				dist[nx][ny][(d + 3) % 4] = dist[x][y][d] + 1;
				Q.push({ nx, ny, (d + 3) % 4 });
			}
		}
	}

	int ans = INF;
	for (int i = 0; i < 4; i++)
		ans = min(ans, dist[ex][ey][i]);

	printf("%d", ans);
}