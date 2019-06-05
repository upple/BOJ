#include <cstdio>

using namespace std;

bool com[101][101]={};
bool visit[101]={0, 1, };
int n;
int dfs(int x)
{
	static int count=0;
	for(int i=1; i<=n; i++)
	{
		if(com[x][i] && !visit[i])
			visit[i]=true, count++, dfs(i);
	}

	return count;
}
int main()
{
	int m;
	scanf("%d %d", &n, &m);

	for(int i=1; i<=m; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);
		com[e][s]=com[s][e]=true;

	}

	printf("%d\n", dfs(1));
	return 0;
}
