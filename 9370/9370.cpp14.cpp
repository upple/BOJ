#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int INF = 111111111;

vector<vector<pair<int, int> > >adj;

void dijk(int start, vector<int> &dist)
{
	priority_queue<pair<int, int> > pq;
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty())
	{
		int cur = pq.top().second;
		pq.pop();
		for (auto &i : adj[cur])
		{
			if (dist[i.first] > dist[cur] + i.second)
			{
				dist[i.first] = dist[cur] + i.second;
				pq.push({ -dist[i.first], i.first });
			}
		}
	}

}
int main()
{
	int tc;
	scanf("%d", &tc);

	while (tc--)
	{
		int n, m, t, s, g, h;
		scanf("%d %d %d %d %d %d", &n, &m, &t, &s, &g, &h);
		adj.assign(n + 1, vector<pair<int, int> >());
		vector<int> dist1(n + 1, INF), dist2(n + 1, INF), dst(t);
		while (m--)
		{
			int a, b, d;
			scanf("%d %d %d", &a, &b, &d);
			adj[b].push_back({ a, d });
			adj[a].push_back({ b, d });
		}

		dijk(s, dist1);
		int mid = (dist1[g] > dist1[h] ? g : h);
		dijk(mid, dist2);

		for (int i = 0; i < t; i++)
			scanf("%d", &dst[i]);

		sort(dst.begin(), dst.end());
		for (int i : dst)
			if (dist1[mid] + dist2[i] == dist1[i])
				printf("%d ", i);
		
		printf("\n");
	}
}