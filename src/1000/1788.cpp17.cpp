#include <iostream>
#include <cstring>
using namespace std;
const int MOD=1000000000;
int dp[1000001];

int solve(int n)
{
	if(dp[n]!=-1) return dp[n];
	if(n>1000000) return dp[n]=(solve(n-1)+solve(n-2));
	else return dp[n]=(solve(n+2)-solve(n+1));
}
int main()
{
	int n;
	cin>>n;
	dp[1]=1;
	if(n<0) 
	{
		n=-n;
		if(n%2==0) cout<<-1<<endl;
		else cout<<1<<endl;
	}
	else
	{
		if(n==0) cout<<0<<endl;
		else cout<<1<<endl;
	}
	
	for(int i=2; i<=n; i++)
		dp[i]=(dp[i-2]+dp[i-1])%MOD;

	cout<<dp[n];
}