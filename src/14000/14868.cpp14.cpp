#include <iostream>
#include <queue>
using namespace std;
struct xy { int x, y; };
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int map[2002][2002];
int par[100001];
int n, k, c, cnt;
queue<xy> cur;
int getPar(int x)
{
	if (par[x] == x) return x;
	return par[x] = getPar(par[x]);
}
bool check()
{
	for (int i = 1; i <= c; i++)
		if (getPar(i) != c) return false;

	return true;
}
void update(int x, int y)
{
	int i = 4;
	while (i--)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (map[nx][ny] > 0)
		{
			if (getPar(map[nx][ny]) < getPar(map[x][y]))
				par[par[map[nx][ny]]] = par[map[x][y]];

			else
				par[par[map[x][y]]] = par[map[nx][ny]];
		}
	}
}
void flowTime()
{
	int size = cur.size();
	while (size--)
	{
		int x = cur.front().x, y = cur.front().y;
		cur.pop();
		int i = 4;
		while (i--)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (map[nx][ny] == 0) map[nx][ny]=map[x][y], cur.push({ nx, ny });
			if (map[nx][ny] != -1) update(nx, ny);

		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		map[0][i] = map[n + 1][i] = map[i][0] = map[i][n + 1] = -1;

	while (k--)
	{
		int x, y;
		cin >> x >> y;
		c++;
		map[x][y] = par[c] = c;
		update(x, y);
		cur.push({ x, y });
	}

	while (!check())
	{
		flowTime(), cnt++;
	}
	cout << cnt;
}