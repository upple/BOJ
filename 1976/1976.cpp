#include <cstdio>

int main()
{
	int adj[201][201]={};
	int d[1000];

	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
			scanf("%d", &adj[i][j]);

		adj[i][i]=1;
	}

	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if(adj[i][j]==0 && adj[i][k]+adj[k][j]==2)
					adj[i][j]=1;

	for(int i=0; i<m; i++)
		scanf("%d", &d[i]);

	for(int i=1; i<m; i++)
	{
		if(!adj[d[i-1]][d[i]])
		{
			printf("NO");
			return 0;
		}
	}

	printf("YES");
}
