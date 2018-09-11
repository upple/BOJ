#include <bits/stdc++.h>
using namespace std;

int arr[1002][1003];
int dp1[1002][1003], dp2[1002][1003], dp3[1002][1003];
int main()
{
	int n, m;
	cin>>n>>m;

	for(int i=1; i<=n; i++)
	{
		for(int j=2; j<=m+1; j++)
		{
			cin>>arr[i][j];
		}
	}

	int ans=0;
	for(int i=2; i<=m+2; i++)
	{
		for(int j=1; j<=n; j++)
		{
			dp1[j][i]=arr[j][i]+max({dp1[j+1][i-1], dp1[j-1][i-1], dp1[j][i-2]+arr[j][i-1]});
			dp2[j][i]=arr[j][i]+max(dp2[j-1][i-1], dp3[j][i-1]);
			dp3[j][i]=arr[j][i]+max(dp3[j+1][i-1], dp2[j][i-1]);
			
			ans=max({ans, dp1[j][i], dp2[j][i], dp3[j][i]});
		}
	}

	cout<<ans;
}