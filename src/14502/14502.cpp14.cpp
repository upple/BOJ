#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct xy { int x, y; };
int map[8][8];
bool visit[8][8];
int n, m;
int ans = 0;
vector<xy> birus;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void reset()
{
	for (int i = 0; i<n; i++)
		for (int j = 0; j<m; j++)
			visit[i][j] = 0;
}

void bfs()
{
	reset();
	queue<xy> Q;
	int cnt = 0;

	for (auto &i : birus)
		Q.push(i);

	while (Q.size())
	{
		xy cur = Q.front();
		Q.pop();

		for (int i = 0; i<4; i++)
		{
			int nx = cur.x + dx[i], ny = cur.y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] || visit[nx][ny]) continue;

			visit[nx][ny] = 1;
			Q.push({ nx, ny });
			cnt++;
		}
	}

	ans = min(ans, cnt);
}

void solve(int x, int y, int c)
{
	if (c == 3)
	{
		bfs();
		return;
	}

	for (int i = x; i<n; i++)
	{
		for (int j = y; j<m; j++)
		{
			if (!map[i][j])
			{
				map[i][j] = 1;
				solve(i, j + 1, c + 1);
				map[i][j] = 0;
			}
		}
		y = 0;
	}

}

int main()
{
	scanf("%d %d", &n, &m);
	int safe = -3;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2)
				birus.push_back({ i, j });

			else if (!map[i][j])
				safe++;
		}
	}

	ans = safe;
	solve(0, 0, 0);
	printf("%d", safe - ans);
}
