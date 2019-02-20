#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int n, m, k;
struct xy{int x, y, d;};
const int dx[]={0, 0, 1, -1, 0};
const int dy[]={1, -1, 0, 0, 0};

char arr[1002][1002];
int dist[2][11][1002][1002];
bool inQ[2][11][1002][1002];

int bell()
{
	dist[0][0][1][1]=1;
	queue<xy> Q;
	Q.push({1, 1, 0});
	while(Q.size())
	{
		auto[x, y, d]=Q.front();
		Q.pop();

		for(int i=5; i--;)
		{
			int nx=x+dx[i], ny=y+dy[i];
			if(arr[nx][ny]==0) continue;
			if(arr[nx][ny]=='1' && i!=4 && d<k)
			{
				if(dist[1][d+1][nx][ny]>dist[0][d][x][y]+1)
				{
					dist[1][d+1][nx][ny]=dist[0][d][x][y]+1;
					if(inQ[1][d+1][nx][ny]==0)
					{
						inQ[1][d+1][nx][ny]==1;
						Q.push({nx, ny, d+1});
					}
				}
			}
			else if(arr[nx][ny]=='0' || i==4)
			{
				for(int c=0; c<2; c++)
				{
					if(dist[!c][d][nx][ny]>dist[c][d][x][y]+1)
					{
						dist[!c][d][nx][ny]=dist[c][d][x][y]+1;
						if(inQ[!c][d][nx][ny]==0)
						{
							inQ[!c][d][nx][ny]==1;
							Q.push({nx, ny, d});
						}
					}
				}
				
			}
		}
	}

	int ret=INF;
	for(int i=2; i--;)
	{
		for(int j=11; j--;)
		{
			ret=min(ret, dist[i][j][n][m]);
		}
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m>>k;
	for(int i=1; i<=n; i++)
		cin>>arr[i]+1;

	memset(dist, INF, sizeof(dist));
	int ret=bell();
	cout<<(ret==INF?-1:ret);
}