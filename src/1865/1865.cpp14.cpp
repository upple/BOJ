#include<cstdio>
#include<vector>
#define INF 999999999
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n, m, w;
		scanf("%d %d %d", &n, &m, &w);
		vector<vector<pair<int, int> > > adj(n+1);
		vector<int> dist(n+1, INF);
		while (m--)
		{
			int s, e, c;
			scanf("%d %d %d", &s, &e, &c);
			adj[s].push_back({ e, c });
			adj[e].push_back({ s, c });
		}

		while (w--)
		{
			int s, e, c;
			scanf("%d %d %d", &s, &e, &c);
			adj[s].push_back({ e, -c });
		}

		dist[1] = 0;
		for (int k = 0; k <= n; k++)
		{
			bool change = false;
			for (int i = 1; i <= n; i++)
				for (auto j : adj[i])
					if (dist[j.first] > dist[i] + j.second)
						change=true, dist[j.first] = dist[i] + j.second;

			if (k == n)
				printf("%s\n", change ? "YES" : "NO");
		}
	}
}