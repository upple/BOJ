#include <cstdio>
#include <queue>
#include <cmath>
#define MAX 101
using namespace std;
struct xy { double x, y; };

struct edge
{
	int a, b;
	double c;
};
inline bool operator <(const edge a, const edge b)
{
	return a.c > b.c;
}

xy arr[MAX];
int p[MAX];
int n, r;

inline double getDist(xy a, xy b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int Find(int x)
{
	if (p[x] == 0) return x;
	return p[x] = Find(p[x]);
}

double Union(edge &x)
{
	int a = Find(x.a);
	int b = Find(x.b);
	if (a == b) return 0;
	r--;
	if (a > b) swap(a, b);
	p[b] = a;
	return x.c;
}
int main()
{
	scanf("%d", &n);
	r = n - 1;
	for (int i = 1; i <= n; i++)
	{
		double x, y;
		scanf("%lf %lf", &x, &y);
		arr[i] = { x, y };
	}

	priority_queue<edge> pq;

	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			pq.push({ i, j, getDist(arr[i], arr[j]) });

	double ans = 0;
	while (r)
	{
		edge cur = pq.top();
		pq.pop();
		ans += Union(cur);
	}

	printf("%.2lf", ans);
}