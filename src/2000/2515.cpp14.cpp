#include <cstdio>
#include <algorithm>
using namespace std;
pair<int, int> input[300001];
int dp[300001];
int main()
{
	int n, s;
	scanf("%d %d", &n, &s);

	for (int i = 1; i <= n; i++)
		scanf("%d %d", &input[i].first, &input[i].second);

	sort(input + 1, input + n + 1);
	
	for (int i = 1, j=0; i <= n; i++)
	{
		for (j; input[j + 1].first <= input[i].first - s; j++);
		dp[i] = max(dp[i - 1], dp[j] + input[i].second);
	}

	printf("%d", dp[n]);
}