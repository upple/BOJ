#include<stdio.h>
#define max(x, y) (x>y?x:y)
int main()
{
	int dp[1001][1001]={};
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
		{
			int num;
			scanf("%d", &num);
			dp[i][j]=max(dp[i-1][j], dp[i][j-1])+num;
		}
		
	printf("%d\n", dp[n][m]);
}
