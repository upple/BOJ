#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> adj[100001];
stack<int> S;
int scc[100001], d[100001];
bool in[100001];
int n, m, a, b, s, c, ans;

int dfs(int x)
{
	int p = d[x] = ++c;
	S.push(x);
	for (int i : adj[x])
	{
		if (!d[i]) p = min(p, dfs(i));
		else if (!scc[i]) p = min(p, d[i]);
	}

	if (p == d[x])
	{
		s++;
		while (1)
		{
			int t = S.top();
			S.pop();
			scc[t] = s;
			if (t == x) break;
		}
	}

	return p;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b;
		adj[a].push_back(b);
	}

	for (int i = 0; i < n; i++)
		if (!d[i]) dfs(i);

	for (int i = 0; i < n; i++)
		for (int j : adj[i])
			if (scc[i] != scc[j])
				in[scc[j]] = 1;

	for (int i = 1; i <= s; i++)
		if (!in[i])
			ans++;

	cout << ans;
}