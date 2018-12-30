#include <bits/stdc++.h>
using namespace std;

int a[50001];
int dp[3][50001];
int n, s;

int solve(int c, int x)
{
	if(x<s || c<0) return 0;
	if(dp[c][x]) return dp[c][x];
	return dp[c][x]=max(solve(c-1, x-s)+a[x]-a[x-s], solve(c, x-1));
}

int main()
{
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		int x;
		cin>>x;
		a[i]=a[i-1]+x;
	}

	cin>>s;
	cout<<solve(2, n);
}