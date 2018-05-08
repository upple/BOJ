#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int map[802][802];

int main()
{
	int n, p, ans = 0;
	vector<int> adj[802];
	scanf("%d %d", &n, &p);
	for (int i = 1; i <= 400; i++)
	{
		adj[i * 2].push_back(i * 2 + 1);
		adj[i * 2 + 1].push_back(i * 2);
		map[i * 2][i * 2 + 1] = 1;
	}

	while (p--)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		adj[a * 2].push_back(b * 2 + 1);
		adj[a * 2 + 1].push_back(b * 2);
		adj[b * 2].push_back(a * 2 + 1);
		adj[b * 2 + 1].push_back(a * 2);
		map[a * 2 + 1][b * 2] = map[b * 2 + 1][a * 2] = 1;

	}

	while (1)
	{
		vector<int> P(2 * n + 2, 0);
		queue<int> Q;
		Q.push(3);
		while (Q.size())
		{
			int cur = Q.front();
			Q.pop();

			if (cur == 4)
				break;

			for(int i : adj[cur])
			{
				if (map[cur][i] > 0 && !P[i])
				{
					P[i] = cur;
					Q.push(i);
				}
			}
		}

		if (!P[4])
			break;

		for (int cur = 4; cur != 3; cur = P[cur])
		{
			map[P[cur]][cur]--;
			map[cur][P[cur]]++;
		}

		ans++;
	}

	printf("%d", ans);
}