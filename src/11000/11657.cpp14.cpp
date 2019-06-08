#include <cstdio>
#include <vector>
#include <queue>
#define INF 999999999
using namespace std;

struct edge
{
	int v, c;
};
int main()
{
	vector<edge> adj[501];
	int dist[501], visit[501] = {}, intoQ[501] = {};

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		dist[i] = INF;

	while (m--)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back({ b, c });
	}

	queue<int> Q;
	Q.push(1), dist[1] = 0, visit[1]++;
	while (Q.size())
	{
		int cur = Q.front();
		Q.pop(), intoQ[cur] = 0;

		for (auto &next : adj[cur])
		{
			if (dist[next.v] > dist[cur] + next.c)
			{
				dist[next.v] = dist[cur] + next.c;

				
				if (!intoQ[next.v])
					Q.push(next.v), intoQ[next.v] = 1, visit[next.v]++;
			
				if (visit[next.v] == n)
				{
					printf("-1");
					return 0;
				}
			}

		}
	}

	for (int i = 2; i <= n; i++)
		printf("%d\n", (dist[i] == INF ? -1 : dist[i]));
}