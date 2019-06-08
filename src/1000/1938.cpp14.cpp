#include <cstdio>
#include <queue>
using namespace std;
struct state { int x, y, d; };
int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
int n, bx, by, bd, ex, ey, ed, cnt;
char map[52][52];
bool v[51][51][2];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%s", map[i] + 1);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] == '1')
				map[i][j] = 0;

			else if (map[i][j] == 'B')
			{
				for (int k = 0; k < 2; k++)
					if (map[i + dx[k]][j + dy[k]] == 'B' && map[i - dx[k]][j - dy[k]] == 'B')
						bx = i, by = j, bd = k;

			}

			else if (map[i][j] == 'E')
			{
				for (int k = 0; k < 2; k++)
					if (map[i + dx[k]][j + dy[k]] == 'E' && map[i - dx[k]][j - dy[k]] == 'E')
						ex = i, ey = j, ed = k;

			}
		}
	}

	queue<state> Q;
	v[bx][by][bd] = 1;
	Q.push({ bx, by, bd });
	while (Q.size())
	{
		int size = Q.size();
		while (size--)
		{
			int x = Q.front().x, y = Q.front().y, d = Q.front().d;
			Q.pop();
			if (x == ex && y == ey && d == ed)
			{
				printf("%d", cnt);
				return 0;
			}

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i], ny = y + dy[i];
				if (!v[nx][ny][d] && map[nx][ny] && map[nx + dx[d]][ny + dy[d]] && map[nx - dx[d]][ny - dy[d]])
				{
					v[nx][ny][d] = 1;
					Q.push({ nx, ny, d });
				}
			}

			if (!v[x][y][!d])
			{
				for (int i = 0; i < 8; i++)
				{
					if (!map[x + dx[i]][y + dy[i]])
						break;

					if (i == 7)
						v[x][y][!d] = 1, Q.push({ x, y, !d });
				}
			}

		}
		cnt++;
	}
	puts("0");
}