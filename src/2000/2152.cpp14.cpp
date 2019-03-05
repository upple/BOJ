#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#define MAX 10001
using namespace std;

int n, m, s, t;
stack<int> S;
vector<int> adj[MAX], scc[MAX];
int po[MAX], d[MAX], in[MAX], city_cnt[MAX];
int it, scc_len;

int dfs(int x)
{
	int p = d[x] = ++it;
	S.push(x);
	for (int next : adj[x])
	{
		if (d[next] == 0) p = min(p, dfs(next));
		else if (po[next] == 0) p = min(p, d[next]);
	}

	if (p == d[x])
	{
		scc_len++;
		while (1)
		{
			int a = S.top();
			S.pop();
			po[a] = scc_len;
			scc[scc_len].push_back(a);
			if (a == x) break;
		}
	}

	return p;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> s >> t;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}

	for (int i = 1; i <= n; i++)
		if (d[i] == 0) dfs(i);

	for (int i = 1; i <= n; i++)
		for (int j : adj[i])
			if (po[i] != po[j])
				in[po[j]]++;

	queue<int> Q;
	for (int i = 1; i <= scc_len; i++)
		if (in[i] == 0) Q.push(i);

	city_cnt[po[s]] = scc[po[s]].size();
	while (Q.size())
	{
		int cur = Q.front();
		Q.pop();
		for (int ele : scc[cur])
		{
			for (int next : adj[ele])
			{
				if (cur != po[next])
				{
					if (city_cnt[cur]) city_cnt[po[next]] = max(city_cnt[po[next]], city_cnt[cur] + int(scc[po[next]].size()));
					if (--in[po[next]] == 0) Q.push(po[next]);
				}
			}
		}
	}

	cout << city_cnt[po[t]];
}