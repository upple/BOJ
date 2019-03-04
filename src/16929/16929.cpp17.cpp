#include <bits/stdc++.h>
using namespace std;
struct xy{int x, y;};
const int dx[]={0, 0, 1, -1};
const int dy[]={1, -1, 0, 0};
char arr[52][52];
int v[52][52];

bool dfs(int x, int y)
{
	for(int i=4; i--;)
	{
		int nx=x+dx[i], ny=y+dy[i];
		if(arr[nx][ny]!=arr[x][y]) continue;
		if(v[nx][ny]!=0)
		{
			if(v[x][y]>=v[nx][ny]+3) return true;
		}
		else
		{
			v[nx][ny]=v[x][y]+1;
			if(dfs(nx, ny)) return true;
		}
	}

	return false;
}
int main()
{
	int n, m;
	cin>>n>>m;

	for(int i=1; i<=n; i++)
	{
		cin>>arr[i]+1;
	}

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(v[i][j]==0)
			{
				v[i][j]=1;
				if(dfs(i, j)) 
				{
					cout<<"Yes";
					return 0;
				}

			}
		}
	}

	cout<<"No";
}