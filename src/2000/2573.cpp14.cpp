#include <cstdio>
#include <queue>
using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int n, m, map[300][300];

void dfs(int x, int y, int visit[][300])
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && map[nx][ny])
			visit[nx][ny] = true, dfs(nx, ny, visit);
	}
}

int main()
{
	int count=0;
	bool died[300][300] = {}, check=true;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);

	while (1)
	{
		check = false;
		int visit[300][300] = {};
		for(int i=0; i<n; i++)
			for (int j = 0; j < m; j++)
			{
				if (!died[i][j] && !map[i][j])
					died[i][j] = true;

			}

		for (int i = 0; i<n; i++)
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] && !visit[i][j])
				{
					if (check)
					{
						printf("%d", count);
						return 0;
					}

					check = visit[i][j] = true, dfs(i, j, visit);
				}
			}

		if (!check)
		{
			printf("0");
			return 0;
		}
		for (int i = 0; i<n; i++)
			for (int j = 0; j < m; j++)
			{
				if (map[i][j])
				{
					for (int k = 0; k < 4; k++)
					{
						int nx = i + dx[k], ny = j + dy[k];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m && died[nx][ny] && map[i][j])
							map[i][j]--;

					}
				}
			}

		count++;
	}
}