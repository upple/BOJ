#include <bits/stdc++.h>
#define MOD 1000000009
using namespace std;

int dp[1001][1001];
bool v[1001][1001];
int solve(int n, int m)
{
	if(n<=0) return 0;
	if(v[n][m]) return dp[n][m];
	v[n][m]=1;
	return dp[n][m]=((solve(n-1, m-1)+solve(n-2, m-1))%MOD+solve(n-3, m-1))%MOD;
}
int main()
{
	int t;
	cin>>t;
	v[1][1]=v[2][1]=v[3][1]=dp[1][1]=dp[2][1]=dp[3][1]=1;
	while(t--)
	{
		int n, m;
		cin>>n>>m;
		cout<<solve(n, m)<<"\n";
	}
}