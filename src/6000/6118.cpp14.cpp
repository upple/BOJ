#include<cstdio>
#include<queue>
#define INF 90192849
using namespace std;
int main()
{
	int n, m, count=1, min, md=1;
	scanf("%d %d", &n, &m);
	vector<vector<int> >adj(n + 1);
	vector<int> dist(n + 1, INF);
	priority_queue<pair<int, int> > pq;
	while (m--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	pq.push({ 0, -1 });
	dist[1] = 0;
	while (!pq.empty())
	{
		int pos = -pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		dist[pos] > md ? md = dist[min = pos], count = 1 : count++;

		for (auto i : adj[pos])
			if (dist[i] > dist[pos] + 1)
				dist[i] = dist[pos] + 1, pq.push({ -dist[i], -i });

	}

	printf("%d %d %d\n", min, md, count);
}