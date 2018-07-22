#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[101002];
bool visit[101002];

int main()
{
	int n, k, m, count = 0;
	scanf("%d %d %d", &n, &k, &m);

	int h[1001];

	for(int i=1; i<=m; i++)
	{
		for(int j=0; j<k; j++)
		{
			scanf("%d", &h[j]);
		}

		for(int j=0; j<k; j++)
		{
			adj[n+i].push_back(h[j]);
			adj[h[j]].push_back(n+i);
		}
	}

	queue<int> Q;
	Q.push(1);
	visit[1] = true;

	while (Q.size())
	{
		int t = Q.size();
		if(Q.front()<=n)
			count++;
			
		while (t--)
		{
			int cur = Q.front();
			Q.pop();

			if (cur == n)
			{
				printf("%d", count);
				return 0;
			}

			for (int next : adj[cur])
			{
				if (!visit[next])
				{
					visit[next] = true;
					Q.push(next);
				}
			}
		}

	}

	printf("-1");
	return 0;
}
