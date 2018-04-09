#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;

int main()
{
	priority_queue<pair<int, int> > pq;
	int n, num;
	scanf("%d", &n);
	while (scanf("%d", &num)!=EOF)
	{
		if (num)
			pq.push({ -abs(num), -num });

		else if (pq.size())
			printf("%d\n", -pq.top().second), pq.pop();

		else
			printf("0\n");
	}
}