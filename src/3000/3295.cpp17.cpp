#include <bits/stdc++.h>
using namespace std;

vector<int> in, out;
vector<vector<int> > adj;
vector<bool> v;
int n, m;

bool dfs(int x)
{
	v[x]=1;
	for(int i : adj[x])
	{
		if(in[i]==x) continue;
		if(in[i]==-1 || (!v[in[i]] && dfs(in[i])))
		{
			in[i]=x;
			out[x]=i;
			return true;
		}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		adj.assign(n, vector<int>());
		in.assign(n, -1);
		out.assign(n, -1);
		v.resize(n);

		while(m--)
		{
			int u, v;
			cin>>u>>v;
			adj[u].push_back(v);
		}

		int ans=0;
		for(int i=0; i<n; i++)
		{
			fill(v.begin(), v.end(), 0);
			if(out[i]==-1 && dfs(i))
			{
				ans++;
			}
		}

		cout<<ans<<"\n";
	}
}