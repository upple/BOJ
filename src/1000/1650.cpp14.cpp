#include <iostream>
#include <queue>
#include <algorithm>
#define INF 999999999
#define MAX 1001
using namespace std;

int n, m;
class edge
{
public:
	int n, c;
	edge * rvs;
	edge(int _v = 0, int _c = 0)
	{
		n = _v;
		c = _c;
		rvs = 0;
	}
};
vector<vector<edge*> > adj;
vector<int> dist;
edge * path[MAX];
int pr[MAX];
bool inQ[MAX];

void spfa(int s)
{
	dist.assign(2 * n + 1, INF);
	dist[s] = 0;
	queue<int> Q;
	Q.push(s);
	while (Q.size())
	{
		int cur = Q.front();
		Q.pop();
		inQ[cur] = 0;
		for (edge *m : adj[cur])
		{
			if (dist[m->n] > dist[cur] + m->c)
			{
				dist[m->n] = dist[cur] + m->c;
				path[m->n] = m;
				pr[m->n] = cur;
				if (!inQ[m->n]) inQ[m->n] = 1, Q.push(m->n);
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	adj.resize(n + 1);
	while (m--)
	{
		int p, q, l;
		cin >> p >> q >> l;
		edge *e1 = new edge(q, l), *e2 = new edge(p, l);
		e1->rvs = e2, e2->rvs = e1;
		adj[p].push_back(e1);
		adj[q].push_back(e2);
	}

	int ans = 0;
	spfa(1);

	ans += dist[n];
	for (int i = n; i != 1; i = pr[i])
	{
		path[i]->c *= -1;
		path[i]->rvs->c = INF;
	}

	spfa(n);
	ans += dist[1];
	cout << ans;
}