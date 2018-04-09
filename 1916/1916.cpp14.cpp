#include <cstdio>
#include <vector>
#include <queue>
#define INF 999999999999
using namespace std;

typedef long long ll;
int main()
{
	int n, m, s, e;
	scanf("%d %d", &n, &m);
	vector<pair<int, ll> > adj[1001];
	vector<ll> dist(n + 1, INF);

	while (m--)
	{
		int a, b;
		ll c;
		scanf("%d %d %lld", &a, &b, &c);
		adj[a].push_back({ b, c });
	}

	priority_queue<pair<ll, int> > pq;
	scanf("%d %d", &s, &e);
	pq.push({ 0, s });
	dist[s] = 0;
	while (!pq.empty())
	{
		int cur = pq.top().second;
		pq.pop();

		for (auto i : adj[cur])
			if (dist[i.first] > dist[cur] + i.second)
				dist[i.first] = dist[cur] + i.second, pq.push({ -dist[i.first], i.first });
	}

	printf("%d", dist[e]);
}