#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 11111111
using namespace std;
struct edge { int v, c, d; };
inline bool operator <(const edge a, const edge b)
{
	return a.d > b.d;
}
vector<vector<edge> > adj;
vector<vector<int> > d;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, k;
		cin >> n >> k >> m;
		adj.clear(), d.clear();
		adj.resize(n + 1);
		d.assign(n + 1, vector<int>(k + 1, INF));
		
		while (m--)
		{
			int u, v, c, d;
			cin >> u >> v >> c >> d;
			adj[u].push_back({ v, c, d });
		}

		priority_queue<edge> pq;
		pq.push({ 1, 0, 0 });
		d[1][0] = 0;
		while (pq.size())
		{
			int cur = pq.top().v, cost = pq.top().c, dist = pq.top().d;
			pq.pop();
			if (d[cur][cost] < dist) continue;
			if (cur == n)
			{
				cout << dist << "\n";
				goto out;
			}

			for (auto &next : adj[cur])
			{
				if (next.c + cost > k) continue;
				if (d[next.v][next.c + cost] > next.d + dist)
				{
					d[next.v][next.c + cost] = next.d + dist;
					pq.push({ next.v, next.c + cost, next.d + dist });
				}
			}
		}

		cout << "Poor KCM\n";
	out:;
	}
}