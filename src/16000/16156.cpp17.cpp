#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

struct dxy{int d, x, y;};
inline bool operator <(const dxy &a, const dxy &b)
{
    return a.d>b.d;
}
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
	priority_queue<dxy> pq;
	for(int i=0; i<n; i++)
	{
		dist[i][m-1]=0;
		pq.push({0, i, m-1});
		inQ[i][m-1]=1;
		p[i][m-1]=i;
		for(int j=0; j<m; j++)
		{
			cin>>cost[i][j];
		}
	}

	while(pq.size())
	{
		int x=pq.top().x, y=pq.top().y, d=pq.top().d;
		pq.pop();
        if(dist[x][y]<d) continue;
		for(int i=4; i--;)
		{
			int nx=x+dx[i], ny=y+dy[i];
			if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
			if(dist[nx][ny]>d+cost[x][y])
			{
				dist[nx][ny]=d+cost[x][y];
				p[nx][ny]=p[x][y];
                pq.push({dist[nx][ny], nx, ny});
            }
		}
	}

	for(int i=0; i<n; i++)
		ans[p[i][0]]++;

	for(int i=0; i<n; i++)
		cout<<ans[i]<<"\n";
}