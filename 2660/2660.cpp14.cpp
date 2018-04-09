#include <cstdio>
#include <vector>
#define INF 999999999
#define max(x, y) (x>y?x:y)
#define min(x, y) (x<y?x:y)
using namespace std;

int main()
{
	int adj[51][51]={};
	int n, count=0;
	vector<int> ans;
	scanf("%d", &n);
	adj[0][0]=INF;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
			adj[i][j]=INF;

		adj[i][i]=0, adj[i][0]=1;
	}

	while(1)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if(a==-1)
			break;

		adj[a][b]=adj[b][a]=1;
	}

	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if(adj[i][j]>adj[i][k]+adj[k][j])
					adj[i][j]=adj[i][k]+adj[k][j];

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
			adj[i][0]=max(adj[i][0], adj[i][j]);

		adj[0][0]=min(adj[0][0], adj[i][0]);
	}
	for(int i=1; i<=n; i++)
	{
		if(adj[0][0]==adj[i][0])
			ans.push_back(i), count++;
	}

	printf("%d %d\n", adj[0][0], count);
	for(int i=0; i<ans.size(); i++)
		printf("%d ", ans[i]);

	return 0;
}
