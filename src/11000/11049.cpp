#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3fL
using namespace std;

struct rc{int r,c;};
rc arr[501];
long long dp[501][501];
int main()
{
	int n;
	cin>>n;

	for(int i=0; i<n; i++)
	{
		int r, c;
		cin>>r>>c;
		arr[i]={r, c};
	}

	for(int len=1; len<n; len++)
	{
		for(int i=0; i+len<n; i++)
		{
			dp[i][i+len]=INF;
			for(int j=i; j<i+len; j++)
			{
				dp[i][i+len]=min(dp[i][i+len], dp[i][j]+dp[j+1][i+len]+(arr[i].r*arr[j].c*arr[i+len].c));
			}
		}
	}

	cout<<dp[0][n-1];
}