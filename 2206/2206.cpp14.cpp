#include <cstdio>
#include <queue>
using namespace std;
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};

struct xyb
{
	int x, y, b;
};
int main()
{
	int n, m, count=1;
	char arr[1001][1001];
	bool visit[1001][1001][2]={};
	queue<xyb> Q;
	scanf("%d %d", &n, &m);

	for(int i=1; i<=n; i++)
		scanf("%s", arr[i]+1);

	Q.push({1, 1, 0}), Q.push({0, 0, 0});
	visit[1][1][0]=true;

	while(Q.size())
	{
		auto cur=Q.front();
		Q.pop();

		if(!cur.x)
		{
			if(Q.empty())
			{
				printf("-1");
				return 0;
			}

			Q.push({0, 0, 0}), count++;
			continue;
		}

		if(cur.x==n && cur.y==m)
		{
			printf("%d", count);
			return 0;
		}

		for(int i=0; i<4; i++)
		{
			int nx=cur.x+dx[i], ny=cur.y+dy[i], b=cur.b;
			if(b)
			{
				if(nx>0 && nx<=n && ny>0 && ny<=m && !visit[nx][ny][1] && arr[nx][ny]=='0')
					visit[nx][ny][1]=1, Q.push({nx, ny, 1});
			}
			else
			{
				if(nx>0 && nx<=n && ny>0 && ny<=m)
				{
					if(arr[nx][ny]=='1' && !visit[nx][ny][1])
						visit[nx][ny][1]=1, Q.push({nx, ny, 1});

					else if(arr[nx][ny]=='0' && !visit[nx][ny][0])
						visit[nx][ny][0]=1, Q.push({nx, ny, 0});
				}
			}
		}
	}
}
