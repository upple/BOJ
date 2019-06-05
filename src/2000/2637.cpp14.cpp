#include <bits/stdc++.h>
using namespace std;

struct edge{int v, c;};
int main()
{
	int n, m;
	cin>>n>>m;
	vector<vector<edge> > adj(n+1);
	vector<int> in(n+1);
	vector<vector<int> > cost(n+1, vector<int>(n+1));
	while(m--)
	{
		int x, y, k;
		cin>>x>>y>>k;
		adj[y].push_back({x, k});
		in[x]++;
	}

	queue<int> Q;
	for(int i=1; i<=n; i++)
	{
		if(in[i]==0)
		{
			Q.push(i);
			cost[i][i]=1;
		}
	}

	while(Q.size())
	{
		int cur=Q.front();
		Q.pop();
		for(auto &next : adj[cur])
		{
			int v=next.v;
			int c=next.c;

			for(int i=1; i<=n; i++)
				cost[v][i]+=cost[cur][i]*c;
            
			if(--in[v]==0) Q.push(v);
		}
	}

	for(int i=1; i<=n; i++)
	{
		if(cost[n][i]==0) continue;
		cout<<i<<" "<<cost[n][i]<<"\n";
	}
}