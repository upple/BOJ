#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 202
#define INF 999999999
using namespace std;

int n, m;
int cap[MAX][MAX], cost[MAX][MAX], p[MAX];
vector<int> adj[MAX], dist;
bool inQ[MAX];
int START = 0, END = 201;

bool spfa()
{
	dist.assign(MAX, INF);
	queue<int> Q;
	Q.push(START);
	dist[START] = 0;
	while (Q.size())
	{
		int cur = Q.front();
		Q.pop();
		inQ[cur] = 0;
		for (int next : adj[cur])
		{
			if (cap[cur][next] > 0 && dist[next] > dist[cur] + cost[cur][next])
			{
				dist[next] = dist[cur] + cost[cur][next];
				p[next] = cur;
				if (!inQ[next])
				{
					inQ[next] = 1;
					Q.push(next);
				}
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
		cin >> cap[i][END];
		adj[i].push_back(END);
	}
	for (int i = 101; i <= m + 100; i++)
	{
		cin >> cap[START][i];
		adj[START].push_back(i);
	}

	for (int i = 101; i <= m + 100; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> cost[i][j];
			adj[j].push_back(i);
			adj[i].push_back(j);
			cap[i][j] = INF;
			cost[j][i] = -cost[i][j];
		}
	}

	int ans = 0, cnt = 0;
	while (spfa())
	{
		cnt++;
		int flow = INF;
		for (int i = END; i != START; i = p[i])
		{
			flow = min(flow, cap[p[i]][i]);
		}

		for (int i = END; i != START; i = p[i])
		{
			ans += flow * cost[p[i]][i];
			cap[p[i]][i] -= flow;
			cap[i][p[i]] += flow;
		}
	}

	cout << ans;
}