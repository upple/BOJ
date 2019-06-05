#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 5001
using namespace std;

int height[MAX], dp[MAX];
vector<int> adj[MAX];

int find(int x)
{
	if (dp[x] != -1)
		return dp[x];

	if (adj[x].empty())
		return dp[x] = 1;

	for (auto i : adj[x])
		dp[x] = max(dp[x], find(i)+1);

	return dp[x];
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		scanf("%d", &height[i]), dp[i]=-1;

	while (m--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (height[a] > height[b])
			swap(a, b);

		adj[a].push_back(b);
	}

	for (int i = 1; i <= n; i++)
		printf("%d\n", find(i));
}