#include <cstdio>
#include <queue>
using namespace std;

int visit[100001];

int main()
{
	int n, k, count=0;
	scanf("%d %d", &n, &k);

	queue<int> Q;
	while (n <= 100000 && !visit[n])
	{
		visit[n] = 1;
		Q.push(n);
		n *= 2;
	}
	while (Q.size())
	{
		int Qsize = Q.size();
		while (Qsize--)
		{
			int cur = Q.front();
			Q.pop();

			if (cur == k)
			{
				printf("%d", count);
				return 0;
			}

			if (cur > 0 && !visit[cur - 1])
			{
				int temp = cur - 1;
				while (temp <= 100000 && !visit[temp])
				{
					visit[temp] = true;
					Q.push(temp);
					temp *= 2;
				}

			}
			
			if (cur < 100000 && !visit[cur + 1])
			{
				int temp = cur + 1;
				while (temp <= 100000 && !visit[temp])
				{
					visit[temp] = true;
					Q.push(temp);
					temp *= 2;
				}

			}

		}
		
		count++;
	}
}