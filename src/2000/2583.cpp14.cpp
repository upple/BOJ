#include<cstdio>
#include<queue>
using namespace std;

const int move_x[4]={0, 0, 1, -1};
const int move_y[4]={1, -1, 0, 0};
bool arr[101][101]={};
int m, n;

class xy
{
public:
	int x, y;
	xy(int a=0, int b=0): x(a), y(b){}
	xy & operator = (const xy & a)
	{
		x=a.x, y=a.y;
		return *this;
	}
};
int bfs(int x, int y)
{
	int count=1;
	queue<xy> Q;
	Q.push(xy(x, y));
	Q.push(xy());
	arr[x][y]=true;
	while(!Q.empty())
	{
		xy pos=Q.front();
		Q.pop();
		if(pos.x==0)
		{
			if(Q.empty())
				return count;

			Q.push(xy());
			continue;
		}

		for(int i=0; i<4; i++)
		{
			int nx=pos.x+move_x[i], ny=pos.y+move_y[i];
			if(nx>0 && nx<=n && ny>0 && ny<=m && !arr[nx][ny])
				arr[nx][ny]=true, count++, Q.push(xy(nx, ny));
		}
	}
}
int main()
{
	int k, ans=0;
	priority_queue<int, vector<int>, greater<int> > pq;
	scanf("%d %d %d", &m, &n, &k);
	for(int i=0; i<k; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for(int k=x1+1; k<=x2; k++)
			for(int j=y1+1; j<=y2; j++)
				arr[k][j]=true;
	}
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(!arr[i][j])
				ans++, pq.push(bfs(i, j));

	int size=pq.size();
	printf("%d\n", size);

	while(size--)
		printf("%d ", pq.top()), pq.pop();
}
