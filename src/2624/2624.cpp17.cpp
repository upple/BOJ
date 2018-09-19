#include <bits/stdc++.h>
using namespace std;

int t, k;
pair<int, int> money[101];
int dp[101][10001];
bool v[101][10001];

int solve(int x, int cur_money)
{
	if(cur_money==0) return 1;
	if(cur_money<0 || x<0) return 0;
	if(v[x][cur_money]) return dp[x][cur_money];
	
	v[x][cur_money]=1;
	for(int i=0; i<=money[x].second; i++)
	{
		dp[x][cur_money]+=solve(x-1, cur_money-(i*money[x].first));
	}

	return dp[x][cur_money];
}
int main()
{
	cin>>t>>k;
	for(int i=0; i<k; i++)
		cin>>money[i].first>>money[i].second;

	cout<<solve(k-1, t);
}