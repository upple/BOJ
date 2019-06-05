#include <cstdio>
#include <vector>
using namespace std;

struct lr
{
	int l, r;
};

lr adj[1001];
vector<bool> visit;
vector<int> p;

bool dfs(int x)
{
	visit[x] = true;
	int l = adj[x].l, r = adj[x].r;
	for (int i = l; i <= r; i++)
	{
		if (!p[i] || (!visit[p[i]] && dfs(p[i])))
		{
			p[i] = x;
			return true;
		}
	}
	return false;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m, ans = 0;
		scanf("%d %d", &n, &m);
		p.assign(n + 1, 0);
		for (int i = 1; i <= m; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			adj[i] = { a, b };
		}

		for (int i = 1; i <= m; i++)
		{
			visit.assign(m + 1, false);
			if (dfs(i))
				ans++;
		}

		printf("%d\n", ans);
	}
}