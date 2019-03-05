#include <cstdio>

using namespace std;
const int move_x[4]={0, 0, -1, 1};
const int move_y[4]={1, -1, 0, 0};

int adj[502][501]={};
int dp[502][501]={};
bool visit[501][501]={};
int row, col;
int dfs(int n, int m)
{
	if(visit[n][m])
		return dp[n][m];

	for(int i=0; i<4; i++)
	{
		int px=n+move_x[i], py=m+move_y[i];
		if(px>0 && px<=row && py>0 && py<=col && adj[n][m]<adj[px][py])
			dp[n][m]+=dfs(px, py);
	}

	visit[n][m]=true;
	return dp[n][m];
}
int main()
{
	scanf("%d %d", &row, &col);
	for(int i=1; i<=row; i++)
		for(int j=1; j<=col; j++)
			scanf("%d", &adj[i][j]);

	dp[1][1]=1;
	visit[1][1]=true;
	printf("%d\n", dfs(row, col));
}
