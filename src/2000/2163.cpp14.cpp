#include<cstdio>
#define min(x, y) ((x)<(y)?(x):(y))
#define INF 10947582;
using namespace std;

int n;
int dp[301][301]={};
int func(int n, int m)
{
	if(dp[n][m])
		return dp[n][m];

	if(n==1 && m==1)
		return 0;

	int ans=INF;
	for(int i=1; i<=n/2; i++)
		ans=min(ans, func(i, m)+func(n-i, m));

	for(int i=1; i<=m/2; i++)
		ans=min(ans, func(n, i)+func(n, m-i));

	return dp[n][m]=dp[m][n]=ans+1;
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	printf("%d\n", func(n, m));
	return 0;
}
