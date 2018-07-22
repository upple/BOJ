#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n, m, find[10], pasty=0, count=1, cur;
		scanf("%d", &n);
		vector<int> adj[100001];
		pair<int, int> ans[100001];
		for (int i = 0; i < n; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			adj[x].push_back(y);
		}

		cur = 0;
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
			scanf("%d", &find[i]);

		for (int i=0; i<=100000; i++)
		{
			if (count > n)
				break;

			if (adj[i].empty())
				continue;

			sort(adj[i].begin(), adj[i].end());

			if (adj[i].back() == pasty)
			{
				for (int j = adj[i].size() - 1; j >= 0; j--, count++)
					ans[count] = { i, adj[i][j] };

				pasty = adj[i].front();
			}

			else
			{
				for (int j = 0; j < adj[i].size(); j++, count++)
					ans[count] = { i, adj[i][j] };

				pasty = adj[i].back();
			}

		}

	out:

		for (int i = 0; i < m; i++)
			printf("%d %d\n", ans[find[i]].first, ans[find[i]].second);
	}
}
