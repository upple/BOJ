#include <cstdio>
#include <queue>
using namespace std;

struct xy
{
	int x, y;
};

int r, c, oCount=0, vCount=0;
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};
int visit[250][250]={};
char map[250][251];

void bfs(int x, int y)
{
	queue<xy> Q;
	int Co=0, Cv=0;

	Q.push({x, y});
	visit[x][y]=true;
	while(Q.size())
	{
		xy cur=Q.front();
		Q.pop();
		switch(map[cur.x][cur.y])
		{
		case 'o':
			Co++; break;

		case 'v':
			Cv++; break;
		}

		for(int i=0; i<4; i++)
		{
			int nx=cur.x+dx[i], ny=cur.y+dy[i];
			if(nx>=0 && nx<r && ny>=0 && ny<c && !visit[nx][ny])
				Q.push({nx, ny}), visit[nx][ny]=1;
		}
	}

	Co>Cv?oCount+=Co:vCount+=Cv;
}
int main()
{
	scanf("%d %d", &r, &c);

	for(int i=0; i<r; i++)
	{
		scanf("%s", map[i]);
		for(int j=0; j<c; j++)
		{
			if(map[i][j]=='#')
				visit[i][j]=1;
		}
	}

	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			if(!visit[i][j])
				bfs(i, j);

	printf("%d %d", oCount, vCount);
}
