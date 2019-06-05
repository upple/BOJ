#include <cstdio>
#include <queue>
using namespace std;

struct xy
{
	int x, y;
};

int dx[]={0, 1, 0, -1};
int dy[]={1, 0, -1, 0};
int main()
{
	int n, k, l, cur_time=0, cur_dir=0, count=0;
	int visit[101][101]={};
	queue<xy> Q;
	xy head={1, 1};
	Q.push(head);
	visit[1][1]=1;
	scanf("%d %d", &n, &k);
	for(int i=0; i<k; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		visit[x][y]=2;
	}

	scanf("%d", &l);
	while(1)
	{
		int x, d;
		char c;

		d=(scanf("%d %c", &x, &c)==EOF?10000:x-cur_time);
		for(int i=1; i<=d; i++)
		{
			int nx=head.x+dx[cur_dir], ny=head.y+dy[cur_dir];
			count++;

			if(nx<=0 || nx>n || ny<=0 || ny>n || visit[nx][ny]==1)
			{
				printf("%d", count);
				return 0;
			}

			if(visit[nx][ny]==0)
			{
				visit[Q.front().x][Q.front().y]=0;
				Q.pop();
			}

			Q.push({nx, ny});
			visit[nx][ny]=1;
			head={nx, ny};
		}

		cur_dir=(c=='L'?(cur_dir+3)%4:(cur_dir+1)%4);
		cur_time=x;
	}

}
