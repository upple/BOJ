#include<cstdio>
#include <queue>
using namespace std;

int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};
int n;
char arr[100][101];
int bfs(int c)
{
	bool visit[100][100]={};
	int count=0;
	if(c==2)
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(arr[i][j]=='R')
					arr[i][j]='G';

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(!visit[i][j])
			{
				count++;
				queue<pair<int, int> > Q;
				int color=arr[i][j];
				Q.push({i, j});
				visit[i][j]=true;
				while(!Q.empty())
				{
					int x=Q.front().first, y=Q.front().second;
					Q.pop();
					for(int k=0; k<4; k++)
					{
						int nx=x+dx[k], ny=y+dy[k];
						if(nx>=0 && nx<n && ny>=0 && ny<n && !visit[nx][ny] && arr[nx][ny]==color)
							visit[nx][ny]=true, Q.push({nx, ny});
					}
				}
			}

	return count;
}
int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%s", arr[i]);

	int a=bfs(1);
	int b=bfs(2);

	printf("%d %d", a, b);
}
