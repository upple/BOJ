#include <stdio.h>
#define max(x, y) (x>y?x:y)
using namespace std;
int move_x[4]={0, 0, 1, -1};
int move_y[4]={1, -1, 0, 0};
int n;
int **arr, **visit;
int dfs(int x, int y)
{
	if(visit[x][y])
		return visit[x][y];

	for(int i=0; i<4; i++)
	{
		int nx=x+move_x[i], ny=y+move_y[i];
		if(nx>=0 && nx<n && ny>=0 && ny<n && arr[nx][ny]<arr[x][y])
			visit[x][y]=max(visit[x][y], dfs(nx, ny)+1);
	}
	if(!visit[x][y])
		visit[x][y]=1;
	return visit[x][y];
}
int main()
{
	int k=0, mx=0;
	scanf("%d", &n);
	arr=new int*[n], visit=new int*[n];
	for(int i=0; i<n; i++)
		arr[i]=new int[n+2], visit[i]=new int[n];

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &arr[i][j]);

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(!visit[i][j])
			{
				int temp=dfs(i, j);
				mx=(mx>temp?mx:temp);
			}

	printf("%d", mx);
	for(int i=0; i<n; i++)
		delete []arr[i], delete []visit[i];

	delete []arr, delete []visit;
}
