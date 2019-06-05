#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int n, m;
int sx, sy, ex, ey;
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};
char arr[300][301];
int d[300][300];
int bfs()
{
	priority_queue<pair<int, pair<int, int> > > pq;
	pq.push({0, {--sx, --sy}});
	while(pq.size())
	{
		int cost = -pq.top().first, x=pq.top().second.first, y=pq.top().second.second;
		pq.pop();

		if(d[x][y]<=cost) continue;
		d[x][y]=cost;
		for(int i=4; i--;)
		{
			int nx=x+dx[i], ny=y+dy[i];
			if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
			int ncost=d[x][y]+(arr[nx][ny]!='0');
			if(d[nx][ny]>ncost)
			{
				pq.push({-ncost, {nx, ny}});
			}
		}
	}

	return d[--ex][--ey];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	cin>>n>>m;
	memset(d, INF, sizeof(d));
	cin>>sx>>sy>>ex>>ey;
	for(int i=0; i<n; i++)
		cin>>arr[i];

	cout<<bfs();
}