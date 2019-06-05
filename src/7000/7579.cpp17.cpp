#include <bits/stdc++.h>
using namespace std;

int a[100], c[100], dp[10001][100];
int n, m, l, r;
int solve(int p, int cost)
{
	if(p<0) return 0;
	if(dp[cost][p]!=-1) return dp[cost][p];
	if(cost<c[p]) return solve(p-1, cost);
	return dp[cost][p]=max(solve(p-1, cost), solve(p-1, cost-c[p])+a[p]);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=0; i<n; i++)
		cin>>a[i];

	for(int i=0; i<n; i++)
	{
		cin>>c[i];
		r+=c[i];
	}

	l=0;

	int ans=1e9;
	while(l<=r)
	{
		int mid=l+r>>1;
		memset(dp, -1, sizeof(dp));
		
		int ret=solve(n-1, mid);

		if(ret>=m)
		{
			ans=min(ans, mid);
			r=mid-1;
		}
		else l=mid+1;
	}

	cout<<ans;
}
