#include <cstdio>
#include <vector>
using namespace std;

vector<int> adj[201];
vector<bool> visit;
int p[201] = {};

bool dfs(int x)
{
	visit[x] = true;
	for (int &i : adj[x])
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
	int n, m, ans=0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		int s;
		scanf("%d", &s);

		adj[i].resize(s);
		for (auto &j : adj[i])
			scanf("%d", &j);
	}

	for (int i = 1; i <= n; i++)
	{
		visit.assign(n + 1, false);
		if (dfs(i))
			ans++;
	}
	
	printf("%d", ans);
}