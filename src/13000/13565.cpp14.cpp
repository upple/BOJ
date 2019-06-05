#include <cstdio>
#include <queue>
using namespace std;

int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};
struct xy
{
	int x, y;
};

char arr[1000][1001];
int main()
{
	int n, m;
	queue<xy> Q;
	scanf("%d %d", &n, &m);

	for(int i=0; i<n; i++)
	{
		scanf("%s", arr[i]);
		if(i==0)
		{
			for(int j=0; j<m; j++)
			{
				if(arr[i][j]=='0')
				{
					Q.push({i, j});
					arr[i][j]='1';
				}
			}

		}
	}

	while(Q.size())
	{
		int x=Q.front().x, y=Q.front().y;
		Q.pop();

		if(x==n-1)
		{
			printf("YES");
			return 0;
		}

		for(int i=0; i<4; i++)
		{
			int nx=x+dx[i], ny=y+dy[i];
			if(nx>=0 && nx<n && ny>=0 && ny<m && arr[nx][ny]=='0')
			{
				Q.push({nx, ny});
				arr[nx][ny]='1';
			}
		}
	}

	printf("NO");
}
