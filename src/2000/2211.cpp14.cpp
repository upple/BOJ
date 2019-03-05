#include<cstdio>
#include<vector>
#include<queue>
#include<set>
using namespace std;
int p[1001] = {};

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	vector<vector<pair<int, int> > > adj(n + 1);
	vector<int> dist(n+1, 9999999), p(n+1, 0);
	priority_queue<pair<int, int> > pq;
	set<pair<int, int> > s;
	while (m--)
	{
		int s, e, c;
		scanf("%d %d %d", &s, &e, &c);
		adj[s].push_back({ c, e });
		adj[e].push_back({ c, s });
	}

	pq.push({ 0, 1 });
	dist[1] = 0;
	while (!pq.empty())
	{
		int pos = pq.top().second;
		int cost = -(pq.top().first);
		pq.pop();
		for (auto i : adj[pos])
			if (dist[i.second] > cost + i.first)
			{
				dist[i.second] = cost + i.first;
				pq.push({ -dist[i.second], i.second });
				p[i.second] = pos;
			}
				
	}
	
	for (int i = 1; i <= n; i++)
	{
		int t = i;
		while (p[t])
		{
			int temp = p[t];
			if (t > temp)
				s.insert({ t, temp });

			else
				s.insert({ temp, t });
			p[t] = 0;
			t = temp;
		}
	}

	printf("%d\n", s.size());
	for (auto i : s)
		printf("%d %d\n", i.first, i.second);
}