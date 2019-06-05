#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#define MAX 500001
using namespace std;

vector<vector<int> > adj;
vector<int> d, p_scc, in;
int n, m, scc_num, it;
stack<int> S;
int dfs(int x)
{
	int p = d[x] = ++it;
	S.push(x);
	for (int i : adj[x])
	{
		if (!d[i]) p = min(p, dfs(i));
		else if (p_scc[i] == -1) p = min(p, d[i]);
	}

	if (p == d[x])
	{
		while (1)
		{
			int t = S.top();
			S.pop();
			p_scc[t] = scc_num;
			if (t == x) break;
		}

		scc_num++;
	}

	return p;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		scc_num = it = 0;

		adj.clear();
		adj.resize(n), d.assign(n, 0), p_scc.assign(n, -1);
		while (m--)
		{
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
		}


		for (int i = 0; i < n; i++)
			if (!d[i]) dfs(i);
		
		in.assign(scc_num, 0);
		for (int i = 0; i < n; i++)
			for (int j : adj[i])
				if (p_scc[i] != p_scc[j])
					in[p_scc[j]]++;


		int start_scc = -1, cnt = 0;
		for (int i = 0; i < scc_num; i++)
			if (!in[i])	start_scc = i, cnt++;

		if (cnt != 1)
			cout << "Confused\n";

		else
		{
			for (int i = 0; i < n; i++)
				if (p_scc[i] == start_scc)
					cout << i << "\n";
		}

		cout << "\n";
	}
}