#include <cstdio>
#include <queue>
using namespace std;

int main()
{
	int n, ans=0;
	scanf("%d", &n);

	priority_queue<int> pq;
	pq.push(n);
	while(pq.top() != 1)
	{
		int cur = pq.top();
		pq.pop();
		if (cur % 2 == 0)
		{
			pq.push(cur / 2);
			pq.push(cur / 2);
			ans += (cur / 2)*(cur / 2);
		}

		else
		{
			pq.push(cur / 2);
			pq.push(cur / 2 + 1);
			ans += (cur / 2)*(cur / 2 + 1);
		}
	}

	printf("%d", ans);
}