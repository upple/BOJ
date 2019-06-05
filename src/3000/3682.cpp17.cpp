#include <bits/stdc++.h>
#define MAX 20001
using namespace std;

int d[MAX], s[MAX], in[MAX], out[MAX], it, ans, scc_num;
stack<int> S;
vector<vector<int> > adj, scc;
int dfs(int x)
{
	int p=d[x]=++it;
	S.push(x);
	for(int i : adj[x])
	{
		if(!d[i]) p=min(p, dfs(i));
		else if(!s[i]) p=min(p, d[i]);
	}

	if(p==d[x])
	{
		scc_num++;
		while(1)
		{
			int t=S.top();
			S.pop();
			scc[scc_num].push_back(t);
			s[t]=scc_num;
			if(t==x) break;
		}
	}

	return p;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;

	while(t--)
	{
		int n, m;
		cin>>n>>m;
		adj.clear(), scc.clear();
		adj.resize(n+1), scc.resize(n+1);
		memset(d, 0, 4*MAX);
		memset(s, 0, 4*MAX);
		memset(in, 0, 4*MAX);
		memset(out, 0, 4*MAX);
		ans=it=scc_num=0;

		while(m--)
		{
			int a, b;
			cin>>a>>b;
			adj[a].push_back(b);
		}

		for(int i=1; i<=n; i++)
			if(!d[i]) dfs(i);

		for(int i=1; i<=scc_num; i++)
		{
			for(int j : scc[i])
			{
				for(int k : adj[j])
				{
					if(s[k]!=s[j]) 
					{
						in[s[k]]++;
						out[s[j]]++;
					}
				}
			}
		}

		if(scc_num==1)
		{
			cout<<0<<"\n";
			continue;
		}
		int ii=0, oo=0;
		for(int i=1; i<=scc_num; i++)
		{
			if(in[i]==0) ii++;
			if(out[i]==0) oo++;
		}
		cout<<max(ii, oo)<<"\n";
	}
}