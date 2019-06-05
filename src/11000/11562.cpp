#include <cstdio>
#define INF 9999
int adj[251][251];
int main()
{
	int n, m, u, v, b, k, s, e;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			adj[i][j] = INF;

		adj[i][i] = 0;
	}

	while (m--)
	{
		scanf("%d %d %d", &u, &v, &b);
		
		adj[u][v] = 0;
		adj[v][u] = b ? 0 : 1;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (adj[i][j] > adj[i][k] + adj[k][j])
					adj[i][j] = adj[i][k] + adj[k][j];

	scanf("%d", &k);
	while (k--)
	{
		scanf("%d %d", &s, &e);
		printf("%d\n", adj[s][e]);
	}
}