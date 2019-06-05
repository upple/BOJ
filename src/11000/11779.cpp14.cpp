#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#define INF 1111111111
using namespace std;

struct vc
{
	int v, c;
};
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, s, e;
	cin >> n >> m;

	vector<vc> adj[1001];
	vector<int> dist(n + 1, INF), intoQ(n+1, 0), path(n+1, 0);
	queue<int> Q;
	stack<int> S;
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
	}

	cin >> s >> e;
	dist[s] = 0;
	Q.push(s);
	intoQ[s] = 1;
	while (Q.size())
	{
		int cur = Q.front();
		Q.pop();
		intoQ[cur] = 0;
		for (auto &i : adj[cur])
		{
			if (dist[i.v] > dist[cur] + i.c)
			{
				dist[i.v] = dist[cur] + i.c;
				path[i.v] = cur;
				if (!intoQ[i.v])
					intoQ[i.v] = 1, Q.push(i.v);
			}
		}
	}

	int cur = e;
	while (cur)
	{
		S.push(cur);
		cur = path[cur];
	}

	cout << dist[e] << "\n" << S.size() << "\n";
	while (S.size())
	{
		cout << S.top() << " ";
		S.pop();
	}
}