#include <cstdio>
#define INF 999999
int main()
{
	int adj[201][201], fst[201][201] = {};
	int n, m;
	scanf("%d %d", &n, &m);
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			adj[i][j] = INF;

		adj[i][i] = 0;
	}
	while (m--)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (adj[a][b] <= c)
			continue;

		adj[a][b] = adj[b][a] = c;
		fst[a][b] = b;
		fst[b][a] = a;
	}

	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if (adj[i][j] > adj[i][k] + adj[k][j])
				{
					adj[i][j] = adj[i][k] + adj[k][j];
					fst[i][j] = fst[i][k];
				}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (!fst[i][j])
				printf("- ");

			else
				printf("%d ", fst[i][j]);
		}
		printf("\n");
	}
}