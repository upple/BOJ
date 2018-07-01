#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int dx[] = { 0, 0, 1, -1, 0 };
int dy[] = { 1, -1, 0, 0, 0 };
int n, ans=99999;
int map[10][10];
vector<pair<int, int> > seed;
void solve(int x, int y, int c)
{
	static int cur = 0;
	if (c == 3)
	{
		ans = min(ans, cur);
		return;
	}

	if (y >= n - 1)
		x++, y = 1;

	for (int i = x; i < n - 1; i++)
	{
		for (int j = y; j < n - 1; j++)
		{
			bool chk = 1;
			for (auto &k : seed)
			{
				int dist = abs(i - k.first) + abs(j - k.second);
				if (dist < 3)
				{
					chk = 0;
					break;
				}

			}

			if (chk)
			{
				for (int k = 0; k < 5; k++)
					cur += map[i + dx[k]][j + dy[k]];

				seed.push_back({ i, j });
				solve(i, j + 3, c + 1);
				seed.pop_back();

				for (int k = 0; k < 5; k++)
					cur -= map[i + dx[k]][j + dy[k]];
			}
		}

		y = 1;
	}
}
int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d ", &map[i][j]);

	solve(1, 1, 0);
	printf("%d", ans);
}