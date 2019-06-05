#include <cstdio>
#include <algorithm>
using namespace std;
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
char map[752][752];
bool visit[751][751];
int cnt;
void dfs(int x, int y)
{
	visit[x][y] = 1;
	cnt++;
	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];

		if (map[nx][ny] == '.' && !visit[nx][ny])
			dfs(nx, ny);
	}

}
int main()
{
	int w, h, ans=0;
	scanf("%d %d", &w, &h);

	for (int i = 1; i <= h; i++)
	{
		scanf("%s", map[i] + 1);
	}

	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			if (map[i][j] == '.' && !visit[i][j])
			{
				dfs(i, j);
				ans = max(ans, cnt);
				cnt = 0;
			}
		}
	}

	printf("%d", ans);
}