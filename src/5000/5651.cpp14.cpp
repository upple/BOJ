#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 301
#define INF 999999999
using namespace std;

class edge
{
public:
	int v, f, r;
	edge *rvs;
	edge(int _v = 0, int _f = 0, int _r = 0) : v(_v), f(_f), r(_r) {};
};
int n, m;

vector<vector<edge*> > adj;
edge* path[MAX];
int pr[MAX];

bool bfs(int x, int y)
{
	vector<bool> v(n + 1);
	queue<int> Q;
	Q.push(x);
	v[x] = 1;
	while (Q.size())
	{
		int cur = Q.front();
		Q.pop();

		if (cur == y) return true;
		for (edge *e : adj[cur])
		{
			int next = e->v;
			int f = e->f, r = e->r;
			if (f > 0 && !v[next])
			{
				v[next] = 1;
				Q.push(next);
				path[next] = e;
				pr[next] = cur;
			}
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin >> k;
	while (k--)
	{
		cin >> n >> m;
		adj.clear();
		adj.resize(n + 1);
		while (m--)
		{
			int f, t, b;
			cin >> f >> t >> b;
			edge *e1, *e2;
			e1 = new edge(t, b, 0);
			e2 = new edge(f, 0, 1);
			e1->rvs = e2, e2->rvs = e1;
			adj[f].push_back(e1);
			adj[t].push_back(e2);
		}

		while (bfs(1, n))
		{
			int min_flow = INF;
			for (int i = n; i != 1; i = pr[i])
				min_flow = min(min_flow, path[i]->f);
			
			for (int i = n; i != 1; i = pr[i])
			{
				path[i]->f -= min_flow;
				path[i]->rvs->f += min_flow;
			}
		}

		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (edge *&e : adj[i])
				if (!e->r && !bfs(i, e->v)) ans++;

		for (int i = 1; i <= n; i++)
			for (edge *&e : adj[i])
				delete e;
		cout << ans << "\n";
	}
}