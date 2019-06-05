#include<cstdio>
#include<queue>
using namespace std;

const int move_x[8]={1, 2, 2, 1, -1, -2, -2, -1};
const int move_y[8]={2, 1, -1, -2, -2, -1, 1, 2};
bool arr[300][300]={};
int n;

class xy
{
public:
	int x, y;
	xy(int a=-1, int b=-1): x(a), y(b){}
};
int bfs(int x1, int y1, int x2, int y2)
{
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			arr[i][j]=false;

	int count=0;
	queue<xy> Q;
	Q.push(xy(x1, y1));
	Q.push(xy());
	arr[x1][y1]=true;
	while(!Q.empty())
	{
		xy pos=Q.front();
		Q.pop();
		if(pos.x==x2 && pos.y==y2)
			return count;

		if(pos.x==-1)
		{
			count++, Q.push(xy());
			continue;
		}


		for(int i=0; i<8; i++)
		{
			int nx=pos.x+move_x[i], ny=pos.y+move_y[i];
			if(nx>=0 && nx<n && ny>=0 && ny<n && !arr[nx][ny])
				arr[nx][ny]=true, Q.push(xy(nx, ny));
		}
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d %d", &n, &x1, &y1, &x2, &y2);

		printf("%d\n", bfs(x1, y1, x2, y2));
	}
}
