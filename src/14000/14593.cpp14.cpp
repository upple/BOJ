#include <cstdio>
#include <queue>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	priority_queue<pair<pair<int, int>, pair<int, int> > > pq;

	for (int i = 1; i <= n; i++)
	{
		int s, c, l;
		scanf("%d %d %d", &s, &c, &l);
		pq.push({ {s, -c}, {-l, i } });
	}

	printf("%d", pq.top().second.second);
}