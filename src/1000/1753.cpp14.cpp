#include<cstdio>
#include<vector>
#include<queue>
#define INF 123570270
using namespace std;

int main()
{
	int v, e, s;
	vector<pair<int, int> > adj[20001];
	int dist[20001];
	bool q[20001] = {};

	scanf("%d %d %d", &v, &e, &s);
	for (int i = 1; i <= v; i++)
		dist[i] = INF;
	
	while (e--)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back({ b, c });
	}

	priority_queue<pair<int, int> > pq;
	pq.push({ 0, s });
	dist[s] = 0;
	while (pq.size())
	{
		int cur = pq.top().second;
		pq.pop(), q[cur]=0;

		for (auto &next : adj[cur])
		{
			if (dist[next.first] > dist[cur] + next.second)
			{
				dist[next.first] = dist[cur] + next.second;
				if (!q[next.first])
					q[next.first] = true, pq.push({ -dist[next.first], next.first });
			}
		}
	}

	for (int i = 1; i <= v; i++)
	{
		if (dist[i] == INF)
			printf("INF\n");

		else
			printf("%d\n", dist[i]);
	}
}