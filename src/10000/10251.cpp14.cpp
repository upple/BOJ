#include <bits/stdc++.h>
#define INF 899999999
using namespace std;

int dx[]={0, -1};
int dy[]={-1, 0};
int cost[2][101][101];
int dp[101][101][2][201];
bool v[101][101][2][201];

int solve(int x, int y, int d, int c)
{
	if(x<=0 || y<=0 || c<0) return INF;
	if(v[x][y][d][c]) return dp[x][y][d][c];
	v[x][y][d][c]=1;
	return dp[x][y][d][c]=min(solve(x+dx[d], y+dy[d], d, c)+cost[d][x+dx[d]][y+dy[d]], solve(x+dx[!d], y+dy[!d], !d, c-1)+cost[!d][x+dx[!d]][y+dy[!d]]);

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;
	while(t--)
	{
		memset(v, 0, 101*101*2*201);
		int n, m, l, g;
		cin>>n>>m>>l>>g;
		for(int i=1; i<=n; i++)
			for(int j=1; j<m; j++)
				cin>>cost[0][i][j];
        
		for(int i=1; i<n; i++)
			for(int j=1; j<=m; j++)
				cin>>cost[1][i][j];
                
		dp[1][1][0][0]=dp[1][1][1][0]=0;
		v[1][1][0][0]=v[1][1][1][0]=1;
		for(int i=1; i<=n+m; i++)
		{
			int ret=min(solve(n, m, 0, i), solve(n, m, 1, i));
			if(ret<=g)
			{
				cout<<l*(n+m-2)+i<<"\n";
				break;
			}

			if(i==n+m) cout<<-1<<"\n";
		}

	}
}