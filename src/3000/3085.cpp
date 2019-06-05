#include <cstdio>
#include <algorithm>
using namespace std;
char map[52][52];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int getMax(int x, int y)
{
	char c = map[x][y];
	int res = 0;
	for (int i = 0; i < 2; i++)
	{
		int cnt = 0, tmp = 0;
		while (++cnt)
		{
			int nx = x + cnt * dx[i], ny = y + cnt * dy[i];
			if (map[nx][ny] != c)
				break;
		}

		tmp += cnt;
		cnt = 0;
		while (++cnt)
		{
			int nx = x - cnt * dx[i], ny = y - cnt * dy[i];
			if (map[nx][ny] != c)
				break;
		}
		tmp += cnt - 1;
		res = max(res, tmp);
	}

	return res;
}
int solve(int x, int y)
{
	int res = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (!map[nx][ny]) continue;

		swap(map[nx][ny], map[x][y]);
		res = max(res, max(getMax(x, y), getMax(nx, ny)));
		swap(map[nx][ny], map[x][y]);
	}

	return res;
}

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", map[i] + 1);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ans = max(ans, solve(i, j));
		}
	}

	printf("%d", ans);
}