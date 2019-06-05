#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct edge
{
	int v, e;
};
int main()
{
	int n, m, s, e;
	vector<edge> adj[100001];
	vector<int> road;
	scanf("%d %d", &n, &m);
	while (m--)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
		road.push_back(c);
	}

	scanf("%d %d", &s, &e);
	sort(road.begin(), road.end());
	int left = 0, right = road.size() - 1;
	int mid = (left + right) / 2;
	while (left <= right)
	{
		int w = road[mid], visit[100001] = {};
		queue<int> Q;
		Q.push(s), visit[s] = 1;
		while (Q.size())
		{
			int cur = Q.front();
			Q.pop();
			if (cur == e)
			{
				left = mid + 1;
				goto out;
			}

			for (auto i : adj[cur])
			{
				if (i.e >= w && !visit[i.v])
					Q.push(i.v), visit[i.v] = 1;
			}
		}

		right = mid - 1;
	out:
		mid = (left + right) / 2;
	}
	
	printf("%d", road[mid]);
}