#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int INF = 111111111;
int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n, d, c;
		scanf("%d %d %d", &n, &d, &c);

		vector<vector<pair<int, int> > > adj(n + 1);
		vector<int> dist(n + 1, INF);
		while (d--)
		{
			int a, b, s;
			scanf("%d %d %d", &a, &b, &s);
			adj[b].push_back({ a, s });
		}

		priority_queue<pair<int, int> > pq;
		dist[c] = 0;
		pq.push({ 0, c });
		while (!pq.empty())
		{
			int cur = pq.top().second;
			pq.pop();
			for (auto &i : adj[cur])
			{
				if (dist[i.first] > dist[cur] + i.second)
					dist[i.first] = dist[cur] + i.second, pq.push({ -dist[i.first], i.first });
			}
		}
		int _count=0, _time=0;
		for (auto i : dist)
		{
			if (i != INF)
			{
				if (_time < i)
					_time = i;

				_count++;
			}
		}

		printf("%d %d\n", _count, _time);
	}
}