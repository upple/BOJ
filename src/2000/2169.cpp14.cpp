#include <bits/stdc++.h>
#define MIN -1111111111;
using namespace std;

int arr[1000][1000], dp[3][1000][1000];
bool v[3][1000][1000];
int dx[]={0, -1, 0, 1};
int dy[]={1, 0, -1, 0};
int n, m;
int solve(int d, int x, int y)
{
	int t=(d+2)%4;
	if(x<0 || x>=n || y<0 || y>=m) return MIN;
	if(v[d][x][y]) return dp[d][x][y];
	dp[d][x][y]=MIN;
	for(int i=3; i--;)
	{
		if(i==t) continue;
		dp[d][x][y]=max(dp[d][x][y], solve(i, x+dx[i], y+dy[i]));
	}

	v[d][x][y]=1;
	dp[d][x][y]+=arr[x][y];
	return dp[d][x][y];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin>>n>>m;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>arr[i][j];

	int ans=MIN;
	for(int i=3; i--;)
	{
		v[i][0][0]=1;
		dp[i][0][0]=arr[0][0];
	}

	for(int i=3; i--;)
		ans=max(ans, solve(i, n-1, m-1));

	cout<<ans;
}
