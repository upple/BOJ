#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, ans=0;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			int x;
			cin>>x;
			if(x==0) dp[i][j]=min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]})+1;
			ans=max(ans, dp[i][j]);
		}
	}

	cout<<ans;
}