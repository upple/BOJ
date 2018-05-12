#include <cstdio>
#include <queue>
using namespace std;

int main()
{
	int n, num;
	priority_queue<int> pq;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		pq.push(-num);
	}

	n *= n - 1;
	while(n--)
	{
		scanf("%d", &num);
		pq.push(-num);
		pq.pop();
	}
	printf("%d", -pq.top());
}