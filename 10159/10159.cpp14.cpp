#include <cstdio>
#define max(x, y) ((x)>(y)?(x):(y))
using namespace std;

int main()
{
	int no_node, no_edge;
	int adj[101][101] = {};
	scanf("%d %d", &no_node, &no_edge);
	
	while (no_edge--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (!adj[a][b])
		{
			adj[a][b] = 1;
			adj[b][0]++;
			adj[a][0]++;
		}
	}

	for (int k = 1; k <= no_node; k++)
		for (int i = 1; i <= no_node; i++)
			for (int j = 1; j <= no_node; j++)
				if ((!adj[i][j]) && adj[i][k] && adj[k][j])
					adj[i][0]++, adj[j][0]++, adj[i][j]=1;

	for (int i = 1; i <= no_node; i++)
		printf("%d\n", no_node-1-adj[i][0]);

} 