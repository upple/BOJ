#include<cstdio>
#include<vector>
#include<queue>
#define INF 123570270
using namespace std;

struct edge
{
	int v, c;
};
int main()
{
	int v, e, s;
	vector<edge> adj[20001];
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

	queue<int> Queue;
	Queue.push(s);
	dist[s] = 0;
	while (Queue.size())
	{
		int cur = Queue.front();
		Queue.pop(), q[cur]=0;

		for (auto &next : adj[cur])
		{
			if (dist[next.v] > dist[cur] + next.c)
			{
				dist[next.v] = dist[cur] + next.c;
				if (!q[next.v])
					q[next.v] = true, Queue.push(next.v);
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