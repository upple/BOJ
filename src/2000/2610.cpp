#include <cstdio>
#include <algorithm>
int adj[101][101];
int max[101], visit[101], ans[101];

int main()
{
	int n, m, cnt = 0;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			adj[i][j] = 222;
		}
		adj[i][i] = 0;
		max[i] = -1;
	}
	while (m--)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		adj[a][b] = adj[b][a] = 1;
		max[a] = max[b] = 1;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if (adj[i][j] > adj[i][k] + adj[k][j])
					adj[j][i] = adj[i][j] = adj[i][k] + adj[k][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (adj[i][j] != 222 && max[i] < adj[i][j])
				max[i] = adj[i][j];

	for (int i = 1; i <= n; i++)
	{
		if (!visit[i])
		{
			cnt++;
			visit[i] = 1;
			int tmp = i;
			for (int j = i + 1; j <= n; j++)
			{
				if (adj[i][j] != 222)
				{
					visit[j] = 1;
					tmp = max[tmp] > max[j] ? j : tmp;
				}
			}

			ans[cnt] = tmp;
		}
	}

	printf("%d\n", cnt);
	std::sort(ans + 1, ans + cnt + 1);
	for (int i = 1; i <= cnt; i++)
		printf("%d\n", ans[i]);
}