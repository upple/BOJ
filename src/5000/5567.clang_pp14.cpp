#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int n, m, count = 0, visit[501] = {}, ans = 0;
	vector<int> adj[501];
	scanf("%d %d", &n, &m);

	while (m--)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	queue<int> Q;
	Q.push(1);
	visit[1] = 1;
	while (count<2 && Q.size())
	{
		int t = Q.size();
		while (t--)
		{
			int cur = Q.front();
			Q.pop();
			for (int next : adj[cur])
			{
				if (!visit[next])
					visit[next] = 1, Q.push(next), ans++;
			}
		}
		count++;
	}

	printf("%d", ans);
}