#include<cstdio>
#include<vector>

#define max(x, y) (x>y?x:y)
using namespace std;

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	vector<int> num(n), dp(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]), dp[i]=num[i];

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (num[i] < num[j] && dp[j] < dp[i] + num[j])
				dp[j] = dp[i] + num[j];

	for(int i=0; i<n; i++)
		ans=max(ans, dp[i]);

	printf("%d\n", ans);
	return 0;
}