#include <bits/stdc++.h>
using namespace std;
const long long INF=0x3f3f3f3f3f3f3f3fL;
vector<pair<long long, int> > adj[100001];
long long dist[100001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m, n, a, b, c;
	cin>>m>>n>>a>>b>>c;

	while(m--)
	{
		int u, v, w;
		cin>>u>>v>>w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}	

	priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;
	memset(dist, INF, sizeof(dist));

	pq.push({0, a});
	int ans=0;
	dist[a]=0;
	while(pq.size())
	{
		auto [cost, cur]=pq.top();
		pq.pop();
		if(dist[cur]<cost) continue;

		for(auto &[next, cost] : adj[cur])
		{
			if(dist[next]<=dist[cur]+cost) continue;
			dist[next]=dist[cur]+cost;
			pq.push({dist[next], next});
		}
	}

	ans=min(dist[b], dist[c]);

	memset(dist, INF, sizeof(dist));
	pq.push({0, b});
	dist[b]=0;
	while(pq.size())
	{
		auto [cost, cur]=pq.top();
		pq.pop();
		if(dist[cur]<cost) continue;

		for(auto &[next, cost] : adj[cur])
		{
			if(dist[next]<=dist[cur]+cost) continue;
			dist[next]=dist[cur]+cost;
			pq.push({dist[next], next});
		}
	}

	cout<<ans+dist[c];
}