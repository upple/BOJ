#include <bits/stdc++.h>
using namespace std;

struct dxy{int d, x, y;};
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};
bool arr[1001][1001], v[2][1001][1001];
int n, m, hx, hy, ex, ey;

int bfs()
{
	queue<dxy> Q;
	int cnt=0;
	Q.push({0, hx, hy});
	v[0][hx][hy]=1;
	while(Q.size())
	{
		int size=Q.size();
		while(size--)
		{
			int d=Q.front().d, x=Q.front().x, y=Q.front().y;
			Q.pop();

			if(x==ex && y==ey) return cnt;
			for(int i=4; i--;)
			{
				int nx=x+dx[i], ny=y+dy[i];
				if(nx<=0 || nx>n || ny<=0 || ny>m) continue;
				if(d==0 && !v[arr[nx][ny]][nx][ny])
				{
					v[arr[nx][ny]][nx][ny]=1;
					Q.push({arr[nx][ny], nx, ny});
				}
				else if(d==1 && !v[1][nx][ny] && !arr[nx][ny])
				{
					v[1][nx][ny]=1;
					Q.push({1, nx, ny});
				}
			}
		}

		cnt++;
	}

	return -1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m>>hx>>hy>>ex>>ey;

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			cin>>arr[i][j];
		}
	}

	cout<<bfs();
}