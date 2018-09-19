#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

struct xy{int x, y;};
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};

int n, m;
int dist[500][500];
int cost[500][500], p[500][500];
bool inQ[500][500];
int ans[500];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	cin>>n>>m;
	memset(dist, INF, 4*500*500);
	queue<xy> Q;
	for(int i=0; i<n; i++)
	{
		dist[i][m-1]=0;
		Q.push({i, m-1});
		inQ[i][m-1]=1;
		p[i][m-1]=i;
		for(int j=0; j<m; j++)
		{
			cin>>cost[i][j];
		}
	}

	while(Q.size())
	{
		int x=Q.front().x, y=Q.front().y;
		Q.pop();
		inQ[x][y]=0;

		for(int i=4; i--;)
		{
			int nx=x+dx[i], ny=y+dy[i];
			if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
			if(dist[nx][ny]>dist[x][y]+cost[x][y])
			{
				dist[nx][ny]=dist[x][y]+cost[x][y];
				p[nx][ny]=p[x][y];
				if(!inQ[nx][ny]) inQ[nx][ny]=1, Q.push({nx, ny});
			}
		}
	}

	for(int i=0; i<n; i++)
		ans[p[i][0]]++;

	for(int i=0; i<n; i++)
		cout<<ans[i]<<"\n";
}