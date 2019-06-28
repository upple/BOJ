#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9;
int dp[1000001];

int main()
{
	int n;
	cin>>n;
	
	dp[0]=1;
	for(int i=1; i<=n; i<<=1)
	{
		for(int j=i; j<=n; j++)
		{
			dp[j]=(dp[j]+dp[j-i])%MOD;
		}
	}

	cout<<dp[n];
}