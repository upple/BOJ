#include <cstdio>
#include <cmath>
#include <algorithm>
#define INF 99999999
using namespace std;


int main()
{
	int dp[100001]={};
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		dp[i]=INF;
		for(int j=1; j*j<=i; j++)
		{
			if(dp[i]>dp[i-j*j]+1)
				dp[i]=dp[i-j*j]+1;
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}
