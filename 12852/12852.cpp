#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

int p[1000001];
int main()
{
	int n, count=0;
	scanf("%d", &n);

	queue<int> Q;
	Q.push(n);
	p[n] = 1;

	while (Q.size())
	{
		int size = Q.size();
		while (size--)
		{
			int cur = Q.front();
			Q.pop();

			if (cur == 1)
			{
				printf("%d\n", count);
				stack<int> S;
				S.push(1);

				do
				{
					cur = p[cur];
					S.push(cur);
				}while (cur != n);

				while (S.size())
				{
					printf("%d ", S.top());
					S.pop();
				}
			}

			if (cur % 3 == 0 && p[cur/3]==0)
			{
				Q.push(cur / 3);
				p[cur / 3] = cur;
			}

			if (cur % 2 == 0 && p[cur / 2] == 0)
			{
				Q.push(cur / 2);
				p[cur / 2] = cur;
			}

			if (cur > 0 && p[cur - 1] == 0)
			{
				Q.push(cur - 1);
				p[cur - 1] = cur;
			}
		}
		count++;
	}
}