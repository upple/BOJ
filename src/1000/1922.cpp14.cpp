#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 100001
using namespace std;

int p[MAX];
int ans, r, n, m;
struct edge { int a, b, c; };
bool operator <(const edge &a, const edge &b)
{
	return a.c > b.c;
}

int Find(int x)
{
	if (x == p[x]) return x;
	return p[x] = Find(p[x]);
}

int Union(edge & x)
{
	int a = Find(x.a);
	int b = Find(x.b);
	if (a == b) return 0;

	if (p[a] > p[b]) swap(a, b);

	p[b] = p[a];
	r--;
	return x.c;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	r = n - 1;
	priority_queue<edge> pq;
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ a, b, c });
	}

	for (int i = 1; i <= n; i++)
		p[i] = i;

	while (r)
	{
		edge cur = pq.top();
		pq.pop();
		ans += Union(cur);
	}

	cout << ans;
}