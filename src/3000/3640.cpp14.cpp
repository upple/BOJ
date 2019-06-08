#include <iostream>
#include <queue>
#include <algorithm>
#define INF 999999999
#define MAX 2001
using namespace std;

int v, e;
int S, E;
vector<vector<int> >adj, cost;
vector<vector<bool> > cap;
vector<int> p, dist;
bool inQ[MAX];

int main()
{
	while (cin >> v >> e)
	{
		S = 1, E = 2 * v;
		adj.clear();
		adj.resize(2 * v + 1);
		cap.assign(2 * v + 1, vector<bool>(2 * v + 1));
		cost.assign(2 * v + 1, vector<int>(2 * v + 1, 0));
		p.assign(2 * v + 1, 0);
		for (int i = 1; i <= v; i++)
		{
			adj[i + v].push_back(i);
			adj[i].push_back(i + v);
			cap[i + v][i] = 1;
		}
		while (e--)
		{
			int a, b, c;
			cin >> a >> b >> c;
			adj[a].push_back(b + v);
			adj[b + v].push_back(a);
			cap[a][b + v] = 1;
			cost[a][b + v] += c;
			cost[b + v][a] -= c;
		}

		int t = 2;
		int ans = 0;
		while (t--)
		{
			dist.assign(2 * v + 1, INF);
			dist[S] = 0;
			queue<int> Q;
			Q.push(S);
			while (Q.size())
			{
				int cur = Q.front();
				Q.pop();
				inQ[cur] = 0;
				for (int next : adj[cur])
				{
					if (cap[cur][next] && dist[next] > dist[cur] + cost[cur][next])
					{
						dist[next] = dist[cur] + cost[cur][next];
						p[next] = cur;
						if (!inQ[next]) inQ[next] = 1, Q.push(next);
					}
				}
			}
			ans += dist[E];
			for (int i = E; i != S; i = p[i])
			{
				cap[p[i]][i] = 0;
				cap[i][p[i]] = 1;
			}
		}

		cout << ans << "\n";
	}
}