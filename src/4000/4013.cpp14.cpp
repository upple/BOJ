#include <bits/stdc++.h>
#define MAX 500001
using namespace std;

vector<vector<int> > scc;
vector<int> adj[MAX], scc_money, in;
vector<bool> bank, posible;
stack<int> S;
int d[MAX], p_scc[MAX], dist[MAX];
int it, scc_num;

int dfs(int x)
{
	int p=d[x]=++it;
	S.push(x);
	for(int i : adj[x])
	{
		if(!d[i]) p=min(p, dfs(i));
		else if(!p_scc[i]) p=min(p, d[i]);
	}

	if(p==d[x])
	{
		scc_num++;
		scc_money.push_back(0);
		while(1)
		{
			int t=S.top();
			S.pop();
			p_scc[t]=scc_num;
			if(t==x) break;
		}
	}

	return p;
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n, m;
	cin>>n>>m;
	while(m--)
	{
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
	}

	scc_money.push_back(0);
	for(int i=1; i<=n; i++)
	{
		int money;
		cin>>money;
		if(!d[i]) dfs(i);
		scc_money[p_scc[i]]+=money;
	}

	scc.resize(scc_num+1);
	in.resize(scc_num+1);
	bank.resize(scc_num+1);
	posible.resize(scc_num+1);
	int s, p;
	cin>>s>>p;
	while(p--)
	{
		int x;
		cin>>x;
		bank[p_scc[x]]=1;
	}

	int ans=0;
	for(int i=1; i<=n; i++)
	{
		for(int j : adj[i])
		{
			if(p_scc[i]!=p_scc[j])
			{
				scc[p_scc[i]].push_back(p_scc[j]);
				in[p_scc[j]]++;
			}
		}
	}

	if(bank[p_scc[s]]) ans=scc_money[p_scc[s]];
	queue<int> Q;
	for(int i=1; i<=scc_num; i++)
		if(!in[i]) Q.push(i);
    
	posible[p_scc[s]]=1;
	while(Q.size())
	{
		int cur=Q.front();
		Q.pop();

		for(int i : scc[cur])
		{
			if(posible[cur])
			{
				posible[i]=1;
				dist[i]=max(dist[i], dist[cur]+scc_money[cur]);
				if(bank[i]) ans=max(ans, dist[i]+scc_money[i]);
			}
			if(--in[i]==0) Q.push(i);
		}
	}
	
	cout<<ans;
}