#include <bits/stdc++.h>
using namespace std;

int n, arr[5001], s[5001], dp[5001];
int main()
{
	cin>>n;

	for(int i=1; i<=n; i++)
	{
		cin>>arr[i];
		s[i]=s[i-1]+arr[i];
	}

	for(int i=1; i<=n; i++)
	{
		for(int j=0; j+i<=n; j++)
		{
			dp[j]=s[i+j]-s[j]-min(dp[j], dp[j+1]);
		}
	}

	cout<<dp[0];
}