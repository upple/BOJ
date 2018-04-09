#include <cstdio>
#include <queue>
using namespace std;

int main()
{
	priority_queue<int> pq;
	int n, num;
	scanf("%d", &n);
	while (scanf("%d", &num)!=EOF)
	{
		if (num)
			pq.push(num);

		else if (pq.empty())
			printf("0\n");

		else
			printf("%d\n", pq.top()), pq.pop();
	}
}