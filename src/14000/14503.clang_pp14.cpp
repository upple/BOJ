#include <cstdio>
int dx[]={0, -1, 0, 1};
int dy[]={-1, 0, 1, 0};
int n, m;
int map[50][50];

int dfs(int x, int y, int d)
{
	static int count=0;
	if(!map[x][y])
		map[x][y]=2, count++;

	int i=d;
	do
	{
		int nx=x+dx[i], ny=y+dy[i];
		i=(i+3)%4;
		if(map[nx][ny]==0)
			return dfs(nx, ny, i);

	} while (i!=d);

	if(map[x+dx[(i+3)%4]][y+dy[(i+3)%4]]!=1)
		return dfs(x+dx[(i+3)%4], y+dy[(i+3)%4], i);

	return count;
}
int main()
{
	int r, c, d;
	scanf("%d %d %d %d %d", &n, &m, &r, &c, &d);

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			scanf("%d", &map[i][j]);

	printf("%d", dfs(r, c, d));
}
