#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int n, m;
	long long arr[1001][1001] = {}, sum=0, ans=0;
	int visit[1001][1001] = {};
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		pair<int, int> large = { 0, 0 };
		for (int j = 1; j <= m; j++)
		{
			scanf("%lld", &arr[i][j]);
			sum += arr[i][j];
			if (arr[large.first][large.second] < arr[i][j])
				large = { i, j };
		}

		visit[large.first][large.second] = 1;
		ans += arr[large.first][large.second];
	}
	for (int i = 1; i <= m; i++)
	{
		pair<int, int> large = { 0, 0 };
		for (int j = 1; j <= n; j++)
		{
			if (arr[large.first][large.second] < arr[j][i])
				large = { j, i };
		}

		if(!visit[large.first][large.second])
			ans += arr[large.first][large.second];
	}

	printf("%lld", sum-ans);
}