#include <iostream>
#include <vector>
#include <queue>
#define INF 9999999999
using namespace std;

struct vc { int v, c; };
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, s, e;
	cin >> n >> m;
	vector<vc> adj[1001];
	vector<int> dist(n + 1, INF);
	vector<bool> intoQ(n + 1, 0);

	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
	}

	queue<int> Q;
	cin >> s >> e;
	Q.push(s);
	dist[s] = 0;

	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		intoQ[cur] = 0;
		for (auto i : adj[cur])
		{
			if (dist[i.v] > dist[cur] + i.c)
			{
				dist[i.v] = dist[cur] + i.c;
				if (!intoQ[i.v])
					Q.push(i.v), intoQ[i.v] = 1;
			}

		}
	}

	cout << dist[e];
}