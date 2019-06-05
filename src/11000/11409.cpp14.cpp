#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 802
#define INF 999999999
using namespace std;

bool cap[MAX][MAX];
int cost[MAX][MAX];
vector<int> adj[MAX], p(MAX), dist;
vector<bool> inQ(MAX);
int n, m;
int START = 0, END = 801;
bool spfa()
{
	dist.assign(MAX, INF);
	dist[START] = 0;
	queue<int> Q;
	Q.push(START);
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

	return dist[END] != INF;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		adj[START].push_back(i);
		adj[i].push_back(START);
		cap[START][i] = 1;
		int c;
		cin >> c;
		while (c--)
		{
			int x, w;
			cin >> x >> w;
			adj[i].push_back(x + 400);
			adj[x + 400].push_back(i);
			cap[i][x + 400] = 1;
			cost[i][x + 400] -= w;
			cost[x + 400][i] += w;
		}
	}

	for (int i = 401; i <= m + 400; i++)
	{
		adj[i].push_back(END);
		adj[END].push_back(i);
		cap[i][END] = 1;
	}

	int ans = 0, cnt = 0;
	while (spfa())
	{
		cnt++;
		ans -= dist[END];

		for (int i = END; i != START; i = p[i])
			cap[p[i]][i] = 0, cap[i][p[i]] = 1;
	}
	cout << cnt << "\n" << ans;
}