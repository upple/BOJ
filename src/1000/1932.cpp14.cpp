#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int dp[2][501]={}, num[501]={};
	int n;
	scanf("%d %d", &n, &dp[0][1]);
	for(int i=2; i<=n; i++)
	{
		for(int j=1; j<=i; j++)
			scanf("%d", &num[j]);

		for(int j=1; j<=i; j++)
			dp[1][j]=max(dp[0][j-1], dp[0][j])+num[j];

		for(int j=1; j<=i; j++)
			dp[0][j]=dp[1][j];
	}

	printf("%d\n", *max_element(dp[0], dp[0]+n+1));
	return 0;
}
