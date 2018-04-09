#include <cstdio>
using namespace std;

const int move_x[8]={0, 1, 1, 1, 0, -1, -1, -1};
const int move_y[8]={1, 1, 0, -1, -1, -1, 0, 1};
bool map[50][50];
int n, m;

void dfs(int x, int y)
{
	for(int i=0; i<8; i++)
	{
		int nx=x+move_x[i], ny=y+move_y[i];
		if(nx>=0 && nx<n && ny>=0 && ny<m && map[nx][ny])
			map[nx][ny]=false, dfs(nx, ny);
	}
}
int main()
{
	while(1)
	{
		int ans=0;
		scanf("%d %d", &m, &n);
		if(n==0)
			break;

		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				scanf("%d", &map[i][j]);

		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(map[i][j])
					ans++, map[i][j]=false, dfs(i, j);

		printf("%d\n", ans);
	}
	return 0;
}
