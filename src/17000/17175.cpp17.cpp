#include <iostream>
using namespace std;
const int MOD=1e9+7;
int dp[51];

int solve(int n)
{
	if(dp[n]) return dp[n];
	if(n<2) return 1;
	return dp[n]=(1+solve(n-2)+solve(n-1))%MOD;
}
int main()
{
	int n;
	cin>>n;
	cout<<solve(n);
}