#include <bits/stdc++.h>
using namespace std;

int dp[101][101][101];
int main()
{
	string a, b, c;
	cin>>a>>b>>c;

	for(int i=0; i<a.size(); i++)
	{
		for(int j=0; j<b.size(); j++)
		{
			for(int k=0; k<c.size(); k++)
			{
				if(a[i]==b[j] && b[j]==c[k])
				{
					dp[i+1][j+1][k+1]=dp[i][j][k]+1;
				}

				else
				{
					dp[i+1][j+1][k+1]=max({dp[i][j][k], dp[i+1][j][k], dp[i][j+1][k], dp[i][j][k+1], dp[i+1][j+1][k], dp[i+1][j][k+1], dp[i][j+1][k+1]});
				}
			}
		}
	}

	cout<<dp[a.size()][b.size()][c.size()];
}