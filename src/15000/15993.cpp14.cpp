#include <bits/stdc++.h>
#define MOD 1000000009
using namespace std;

int dp[2][100001];
bool v[2][100001];
int solve(int c, int n)
{
	if(n<=0) return 0;
	if(v[c][n]) return dp[c][n];
	v[c][n]=1;
	return dp[c][n]=(((solve(!c, n-1)+solve(!c, n-2))%MOD)+solve(!c, n-3))%MOD;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	dp[1][1]=dp[1][2]=dp[0][2]=1;
	dp[1][3]=dp[0][3]=2;
	for(int i=1; i<=3; i++)
		v[0][i]=v[1][i]=1;

	while(t--)
	{
		int n;
		cin>>n;
		cout<<solve(1, n)<<" "<<solve(0, n)<<"\n";
	}
}