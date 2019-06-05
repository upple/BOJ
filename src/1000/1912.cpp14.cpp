#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int MIN = -24151;
int main()
{
	int n;
	scanf("%d", &n);
	int num;
	vector<int> dp(n + 1);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &num);

		if (dp[i - 1] + num > num)
			dp[i] = dp[i - 1] + num;

		else
			dp[i] = num;
	}

	printf("%d\n", *max_element(dp.begin() + 1, dp.end()));
}