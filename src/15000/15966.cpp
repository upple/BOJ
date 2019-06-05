#include <iostream>
#include <algorithm>
using namespace std;
 
int dp[1000001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, ans=0;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		int x;
		cin>>x;
		dp[x]=max(dp[x], dp[x-1]+1);
		ans=max(dp[x], ans);
	}
 
	cout<<ans;
}