#include <bits/stdc++.h>
using namespace std;

int adj[16][16];
int dp[16][1<<16];
int n;

int solve(int p, int h)
{
	if(dp[p][h]) return dp[p][h];
	if(h==(1<<n)-1) return adj[p][0]?adj[p][0]:1e9;

	dp[p][h]=1e9;
	for(int i=0; i<n; i++)
	{
		if(h&(1<<i) || adj[p][i]==0) continue;
		dp[p][h]=min(dp[p][h], adj[p][i]+solve(i, h+(1<<i)));
	}

	return dp[p][h];
}

int main()
{
	cin>>n;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin>>adj[i][j];
		}
	}

	cout<<solve(0, 1);
}