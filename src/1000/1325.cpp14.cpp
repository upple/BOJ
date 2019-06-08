#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<vector<int> >adj;
int bfs(int x)
{
	vector<bool> visit(n+1);
	queue<int> Q;
	int count=1;
	Q.push(x);
	visit[x]=true;
	while(!Q.empty())
	{
		x=Q.front();
		Q.pop();
		for(auto i : adj[x])
			if(!visit[i])
				visit[i]=true, count++, Q.push(i);
	}

	return count;
}
int main()
{
	scanf("%d %d", &n, &m);
	adj.resize(n+1);
	vector<int> ans;
	int max=0;
	while(m--)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		adj[b].push_back(a);
	}

	for(int i=1; i<=n; i++)
	{
		int hack=bfs(i);
		if(hack>max)
			max=hack, ans.clear(), ans.push_back(i);

		else if(hack==max)
			ans.push_back(i);
	}

	for(auto i : ans)
		printf("%d ", i);
}
