#include <cstdio>
using namespace std;

int main()
{
	int no_node, no_edge, n;
	int adj[401][401] = {};
	scanf("%d %d", &no_node, &no_edge);
	
	while (no_edge--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (!adj[a][b])
		{
			adj[a][b] = -1;
			adj[b][a] = 1;
		}
	}

	for (int k = 1; k <= no_node; k++)
		for (int i = 1; i <= no_node; i++)
			for (int j = 1; j <= no_node; j++)
			{
				if (adj[i][k] == -1 && adj[k][j] == -1)
					adj[i][j] = -1;

				else if (adj[i][k] == 1 && adj[k][j] == 1)
					adj[i][j] = 1;
			}

	scanf("%d", &n);
	while (n--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", adj[a][b]);
	}

} 