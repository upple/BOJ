#include <bits/stdc++.h>
using namespace std;

int dp[100001][101];
int w[101], v[101];

int solve(int n, int k)
{
	if(n==0) return 0;
	if(dp[k][n]!=-1) return dp[k][n];
	if(k-w[n]>=0) return dp[k][n]=max(solve(n-1, k-w[n])+v[n], solve(n-1, k));
	return dp[k][n]=solve(n-1, k);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin>>n>>k;

    for(int i=1; i<=n; i++)
    {
        cin>>w[i]>>v[i];
    }

	memset(dp, -1, sizeof(dp));
	cout<<solve(n, k);
}