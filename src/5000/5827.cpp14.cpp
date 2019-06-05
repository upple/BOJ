#include <cstdio>
#include <queue>
#include <algorithm>
#include <bitset>
#define MAX 502
using namespace std;
struct xyd { int x, y, d; };
int Cx, Cy, Dx, Dy, INF = 1 << 20;
char map[MAX][MAX];
int dist[MAX][MAX];
bitset<MAX> inQ[MAX];
queue<xyd> Q;
inline bool checkD(int x, int y)
{
	return x == Dx && y == Dy;
}
bool drop(int &x, int &y, int d)
{
	if (d == 0)
		d = -1;

	while (map[x + d][y] == '.')
	{
		x += d;
		if (checkD(x, y))
			return true;
	}

	return map[x + d][y] == '#';
}
inline void checkV(int x, int y, int d, int c)
{
	if (map[x][y] == '.' && drop(x, y, d) && dist[x][y] > c)
	{
		dist[x][y] = c;
		if (!inQ[x][y])
			Q.push({ x, y, d }), inQ[x][y] = 1;
	}
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		scanf("%s", map[i] + 1);
		for (int j = 1; j <= m; j++)
		{
			dist[i][j] = INF;
			if (map[i][j] == 'C')
			{
				Cx = i, Cy = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'D')
			{
				Dx = i, Dy = j;
				map[i][j] = '.';
			}
		}
	}

	if(!drop(Cx, Cy, 1))
	{
		puts("-1");
		return 0;
	}

	Q.push({ Cx, Cy, 1 });
	dist[Cx][Cy] = 0;

	while (Q.size())
	{
		xyd &cur = Q.front();
		int x = cur.x, y = cur.y, d = cur.d;
		Q.pop();
		inQ[x][y] = 0;

		int lx = x, ly = y - 1, rx = x, ry = y + 1, nd = !d;
		checkV(lx, ly, d, dist[x][y]);
		checkV(rx, ry, d, dist[x][y]);
		checkV(x, y, nd, dist[x][y] + 1);
	}

	printf("%d", dist[Dx][Dy] == 1 << 20 ? -1 : dist[Dx][Dy]);
}