#include <cstdio>
#include <queue>
using namespace std;
struct xy{int x, y;};
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};

int map[100][100], n, m, ans, cnt;

void bfs()
{
	bool visit[100][100]={};
	queue<xy> Q;
	Q.push({0, 0});
	
	while(Q.size())
	{
		xy cur=Q.front();
		Q.pop();
		
		for(int i=0; i<4; i++)
		{
			int nx=cur.x+dx[i], ny=cur.y+dy[i];
			
			if(nx<0 || nx>=n || ny<0 || ny>=m)
				continue;
			
			if(!visit[nx][ny])
			{
				visit[nx][ny]=1;
				if(map[nx][ny])
				{
					map[nx][ny]=0;
					cnt--;
				}
				else
				{
					Q.push({nx, ny});
				}
			}
		}
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			scanf("%d", &map[i][j]);
			if(map[i][j])
			{
				cnt++;
			}
		}
	}
	
	int no_c=cnt;
	while(cnt)
	{
		no_c=cnt;
		bfs();
		ans++;
	}
	
	printf("%d\n%d", ans, no_c);
}