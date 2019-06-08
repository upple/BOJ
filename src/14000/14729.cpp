#include <cstdio>
#include <queue>
using namespace std;

int main()
{
	int n;
	float biggest = 0, num, ans[7];
	priority_queue<float> pq;
	scanf("%d", &n);

	for (int i = 0; i < 7; i++)
	{
		scanf("%f", &num);
		pq.push(num);
	}
	biggest=pq.top(), n -= 7;
	while (n--)
	{
		scanf("%f", &num);
		if (num < biggest)
		{
			pq.pop(), pq.push(num);
			biggest = pq.top();
		}
	}

	for (int i = 6; i >= 0; i--)
		ans[i] = pq.top(), pq.pop();

	for (int i = 0; i < 7; i++)
		printf("%.03f\n", ans[i]);
}