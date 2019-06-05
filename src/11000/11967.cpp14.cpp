#include <cstdio>
#include <vector>
using namespace std;

struct xy { int x, y; };
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

vector<xy> adj[101][101];
bool map[102][102], visit[102][102];
int ans = 1;
int n, m;

void dfs(int x, int y)
{
	visit[x][y] = 1;
	for (auto &i : adj[x][y])
	{
		if (!map[i.x][i.y])
		{
			ans++, map[i.x][i.y] = 1;
			for (int j = 0; j < 4; j++)
			{
				int px = i.x + dx[j], py = i.y + dy[j];
				if (visit[px][py])
					dfs(px, py);
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + x, ny = dy[i] + y;

		if (map[nx][ny] && !visit[nx][ny])
			dfs(nx, ny);

	}

}
int main()
{
	scanf("%d %d", &n, &m);
	while (m--)
	{
		int x, y, a, b;
		scanf("%d %d %d %d", &x, &y, &a, &b);
		adj[x][y].push_back({ a, b });
	}

	map[1][1] = 1;
	dfs(1, 1);
	printf("%d", ans);
}