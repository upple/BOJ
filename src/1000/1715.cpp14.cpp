#include <cstdio>
#include <queue>
using namespace std;

int main()
{
	priority_queue<int> pq;
	int n, num, ans=0;
	scanf("%d", &n);

	while (n--)
	{
		scanf("%d", &num);
		pq.push(-num);
	}
	while (pq.size() != 1)
	{
		int a, b;
		a = pq.top(), pq.pop();
		b = pq.top(), pq.pop();
		ans += -a - b;
		pq.push(a + b);
	}

	printf("%d", ans);
}