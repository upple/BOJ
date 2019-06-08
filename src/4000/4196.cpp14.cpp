#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<vector<int> >adj;
vector<int> d, sn;
vector<bool> in;
stack<int> S;
int it, s, n, m;
int dfs(int x)
{
	d[x] = ++it;
	S.push(x);
	int p = d[x];
	for (int i : adj[x])
	{
		if (!d[i]) p = min(p, dfs(i));
		else if (!sn[i]) p = min(p, d[i]);
	}

	if (p == d[x])
	{
		s++;
		while (1)
		{
			int t = S.top();
			S.pop();
			sn[t] = s;

			if (t == x)
				break;
		}

	}
	return p;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		it = s = 0;
		scanf("%d %d", &n, &m);
		adj.resize(n + 1), d.resize(n + 1), sn.resize(n + 1);
		while (m--)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
		}

		for (int i = 1; i <= n; i++)
			if (!d[i]) dfs(i);

		in.resize(s + 1);
		for (int i = 1; i <= n; i++)
			for (int j : adj[i])
				if (sn[i] != sn[j])
					in[sn[j]] = 1;

		int ans = 0;
		for (int i = 1; i <= s; i++)
			if (!in[i])
				ans++;

		printf("%d\n", ans);
		adj.clear(), d.clear(), sn.clear(), in.clear();
	}
}