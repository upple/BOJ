#include <bits/stdc++.h>
using namespace std;

int dp[1001][2][32];
int t, w;

int main()
{
	cin>>t>>w;
	dp[0][1][1]=-1;
	for(int i=1; i<=t; i++)
	{
		int x;
		cin>>x;
		x--;
		for(int j=1; j<=w+1; j++)
		{
			if(dp[i-1][x][j]==-1)
				dp[i][x][j]=-1;

			else
				dp[i][x][j]=max(dp[i-1][!x][j-1], dp[i-1][x][j])+1;
			dp[i][!x][j]=dp[i-1][!x][j];
		}

	}
	int ans=0;
	for(int i=1; i<=t; i++)
		ans=max({ans, *max_element(dp[i][0]+1, dp[i][0]+w+2), *max_element(dp[i][1]+1, dp[i][1]+w+2)});

	cout<<ans;
}