#include <iostream>
#include <vector>
#include <queue>
#define INF 999999999
using namespace std;
struct edge { int v, c; };
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n, m, w, s, e, c;
		cin >> n >> m >> w;
		vector<vector<edge> > adj(n + 1);
		vector<int> d(n + 1, INF), cnt(n + 1);
		vector<bool> inQ(n + 1);
		bool chk = true;
		while (m--)
		{
			cin >> s >> e >> c;
			adj[s].push_back({ e, c });
			adj[e].push_back({ s, c });
		}
		while (w--)
		{
			cin >> s >> e >> c;
			adj[s].push_back({ e, -c });
		}

		queue<int> Q;
		Q.push(1);
		d[1] = 0;
		while (Q.size() && chk)
		{
			int cur = Q.front();
			Q.pop();
			inQ[cur] = 0;
			for (auto &i : adj[cur])
			{
				if (d[i.v] > d[cur] + i.c)
				{
					d[i.v] = d[cur] + i.c;
					if (i.v == 1)
					{
						chk = 0;
						break;
					}
					if (!inQ[i.v])
					{
						inQ[i.v] = 1;
						Q.push(i.v);
						cnt[i.v]++;
					}
				}
			}
		}

		cout << (!chk ? "YES\n" : "NO\n");
	}
}