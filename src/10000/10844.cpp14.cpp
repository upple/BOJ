#include<cstdio>
#include<vector>
#define max(x, y) (x>y?x:y)
using namespace std;

int main()
{
	int n;
	long long sum=0;
	long long dp[100][10]={};
	scanf("%d", &n);
	for(int i=0; i<10; i++)
		dp[0][i]=1;

	for(int i=1; i<n; i++)
	{
		sum=0;
		for(int j=0; j<10; j++)
		{
			if(j==0)
				dp[i][j]=dp[i-1][j+1]%1000000000;

			else if(j==9)
				dp[i][j]=dp[i-1][j-1]%1000000000;

			else
				dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%1000000000;
		}
	}
	for(int i=1; i<10; i++)
		sum=(sum+dp[n-1][i])%1000000000;
	printf("%lld\n", sum);

}
