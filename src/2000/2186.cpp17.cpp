#include <bits/stdc++.h>
using namespace std;

int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};

int dp[80][100][100];
bool v[80][100][100];
char arr[100][101], str[81];
int n, m, k, len;

int solve(int c, int x, int y)
{
	if(c==len-1) return 1;
	if(v[c][x][y]) return dp[c][x][y];
	v[c][x][y]=1;

	for(int i=4; i--;)
	{
		int q=0, nx=x, ny=y;
		while(q<k)
		{
			q++;
			nx+=dx[i], ny+=dy[i];
			if(nx<0 || nx>=n || ny<0 || ny>=m) break;
			if(arr[nx][ny]!=str[c+1]) continue;
			dp[c][x][y]+=solve(c+1, nx, ny);
		}
	}

	return dp[c][x][y];
}
int main()
{
	cin>>n>>m>>k;

	int ans=0;
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}

	cin>>str;
	len=strlen(str);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(arr[i][j]==str[0])
			{
				ans+=solve(0, i, j);
			}
		}
	}

	cout<<ans;
}