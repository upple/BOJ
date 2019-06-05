#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
vector<int> visit;
int p[1001];

bool dfs(int x)
{
	visit[x]++;
	for (int &i : adj[x])
	{
		if (!p[i] || (visit[p[i]]!=2 && dfs(p[i])))
		{
			p[i] = x;
			return true;
		}
	}
	return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	int n, m;
	cin>>n>>m;
	for (int i = 1; i <= n; i++)
	{
		int s;
		cin>>s;

		adj[i].resize(s);
		for (int &j : adj[i])
			cin>>j;
	}
	
	int ans=0;
	for (int i = 1; i <= n; i++)
	{
		visit.assign(n + 1, 0);
		if (dfs(i))
		{
			ans++;
			if(dfs(i)) ans++;
		}
	}
	
	cout<<ans;
}