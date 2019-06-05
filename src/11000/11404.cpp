#include <cstdio>
#include <algorithm>
#define INF 6000000
using namespace std;

int main()
{
	int adj[101][101] = {};
	int n, m, ans = 0;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			adj[i][j] = INF;

		adj[i][i] = 0;
	}

	while (m--)
	{
		int s, e, c;
		scanf("%d %d %d", &s, &e, &c);
		if (adj[s][e] > c)
			adj[s][e] = c;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (adj[i][j]>adj[i][k] + adj[k][j])
					adj[i][j] = adj[i][k] + adj[k][j];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			printf("%d ", adj[i][j] == INF ? 0 : adj[i][j]);

		printf("\n");
	}

	return 0;
}
