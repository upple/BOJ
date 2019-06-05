#include <cstdio>
#include <algorithm>
using namespace std;
char map[1002][1002];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int n, m;
int solve(int x, int y, int d)
{
	int res = 0;

	while(map[x][y])
	{
		switch (map[x][y])
		{
		case '\\':
			d = d % 2 ? (d + 3) % 4 : (d + 1) % 4; break;
		case '/':
			d = d % 2 ? (d + 1) % 4 : (d + 3) % 4; break;
		}
		x = x + dx[d], y = y + dy[d];
		res++;
	}
	map[x][y] = 1;

	return res;
}
int main()
{
	int res = 0;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		scanf("%s", map[i] + 1);
	}

	for (int i = 1; i <= n; i++)
	{
		if (!map[i][0])
			map[i][0] = 1, res = max(res, solve(i, 1, 0));

		if (!map[i][m + 1])
			map[i][m + 1] = 1, res = max(res, solve(i, m, 2));
	}

	for (int i = 1; i <= m; i++)
	{
		if (!map[0][i])
			map[0][i] = 1, res = max(res, solve(1, i, 1));

		if (!map[n + 1][i])
			map[n + 1][i] = 1, res = max(res, solve(n, i, 3));
	}

	printf("%d", res);
}