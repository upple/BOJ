#include <cstdio>
#include <queue>
using namespace std;

class xyd
{
public:
	int x, y, d;
	bool operator == (xyd &a)
	{
		return (a.x==x && a.y==y && a.d==d);
	}
};
int nd[]={0, 2, 1, 3};
int dx[]={0, 1, 0, -1};
int dy[]={1, 0, -1, 0};
int main()
{
	int map[101][101], visit[101][101][4]={};
	int n, m, count=0;

	scanf("%d %d", &n, &m);

	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			scanf("%d", &map[i][j]);

	xyd start, finish;
	queue<xyd> Q;
	scanf("%d %d %d", &start.x, &start.y, &start.d);
	scanf("%d %d %d", &finish.x, &finish.y, &finish.d);

	start.d=nd[start.d-1], finish.d=nd[finish.d-1];
	Q.push(start);
	visit[start.x][start.y][start.d]==1;
	Q.push({-1, -1, -1});
	while(1)
	{
		xyd cur=Q.front();
		int nx, ny;
		Q.pop();
		if(cur.x==-1)
		{
			Q.push({-1, -1, -1});
			count++;
			continue;
		}

		if(cur==finish)
		{
			printf("%d", count);
			return 0;
		}
		if(!visit[cur.x][cur.y][(cur.d+1)%4])
			Q.push({cur.x, cur.y, (cur.d+1)%4}), visit[cur.x][cur.y][(cur.d+1)%4]=1;
		if(!visit[cur.x][cur.y][(cur.d+3)%4])
			Q.push({cur.x, cur.y, (cur.d+3)%4}), visit[cur.x][cur.y][(cur.d+3)%4]=1;

		nx=cur.x, ny=cur.y;
		for(int i=0; i<3; i++)
		{
			nx+=dx[cur.d], ny+=dy[cur.d];
			if(nx<=0 || nx>n || ny<=0 || ny>m || map[nx][ny])
				break;

			if(!visit[nx][ny][cur.d])
				Q.push({nx, ny, cur.d}), visit[nx][ny][cur.d]=1;
		}
	}
}
