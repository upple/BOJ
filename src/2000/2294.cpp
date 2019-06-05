#include <cstdio>
#include <queue>
using namespace std;
int main()
{
	int n, k, count=0, coin[100], arr[10001] = {};
	queue<int> Q;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &coin[i]);
	}

	Q.push(0);
	Q.push(-1);
	while (Q.size())
	{
		int cur = Q.front();
		Q.pop();
		if (cur == -1)
		{
			if (Q.empty())
			{
				printf("-1");
				return 0;
			}

			Q.push(-1), count++;
			continue;
		}

		if (cur == k)
		{
			printf("%d", count);
			return 0;
		}

		for (int i = 0; i < n; i++)
		{
			if (cur+coin[i]<=10000 && !arr[cur + coin[i]])
				arr[cur + coin[i]] = 1, Q.push(cur + coin[i]);
		}
	}
}