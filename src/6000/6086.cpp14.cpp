#include <iostream>
#include <vector>
#include <cctype>
#include <queue>
#define START 0
#define END 25
#define NO_ALPHA 52
#define INF 11111111
using namespace std;

int cap[NO_ALPHA][NO_ALPHA] = {};
vector<int> adj[NO_ALPHA], p;

bool bfs()
{
	queue<int> Q;
	p.assign(NO_ALPHA, -1);
	Q.push(START);
	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		if (cur == END)
			return true;

		for (int next : adj[cur])
		{
			if (cap[cur][next] > 0 && p[next] == -1)
			{
				p[next] = cur;
				Q.push(next);
			}
		}
	}

	return false;
}

int adjustFlow()
{
	int pos;
	int min_flow = INF;
	for (pos = END; pos != START; pos = p[pos])
	{
		if (min_flow > cap[p[pos]][pos])
			min_flow = cap[p[pos]][pos];
	}
	for (pos = END; pos != START; pos = p[pos])
	{
		cap[p[pos]][pos] -= min_flow;
		cap[pos][p[pos]] += min_flow;
	}

	return min_flow;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, ans = 0;
	cin >> n;
	while (n--)
	{
		char s, e;
		int c;
		cin >> s >> e >> c;
		s = islower(s) ? s - 'a' + 26 : s - 'A';
		e = islower(e) ? e - 'a' + 26 : e - 'A';
		cap[e][s] = cap[s][e] += c;
		adj[s].push_back(e);
		adj[e].push_back(s);
	}

	while (bfs())
		ans += adjustFlow();

	cout << ans;
}
