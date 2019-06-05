#include<cstdio>
using namespace std;

int main()
{
	int adj[501][501] = {};
	int n, e;
	scanf("%d %d", &n, &e);
	while (e--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a][b] = 1;
		adj[a][0]++, adj[b][0]++;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (!adj[i][j] && adj[i][k] && adj[k][j])
					adj[i][0]++, adj[j][0]++, adj[i][j] = 1;

	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (adj[i][0] == n - 1)
			ans++;

	printf("%d\n", ans);
}
