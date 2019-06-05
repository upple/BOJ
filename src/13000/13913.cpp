#include <cstdio>
#include <queue>
using namespace std;

int visit[100001];
int p[100001];
int n, k;
void PrintPath(int x)
{
	if (x != n)
		PrintPath(p[x]);

	printf("%d ", x);
}
int main()
{
	int count=0;
	scanf("%d %d", &n, &k);

	queue<int> Q;
	visit[n] = 1;
	Q.push(n);

	while (Q.size())
	{
		int Qsize = Q.size();
		while (Qsize--)
		{
			int cur = Q.front();
			Q.pop();

			if (cur == k)
			{
				printf("%d\n", count);
				PrintPath(k);
				return 0;
			}

			if (cur > 0 && !visit[cur - 1])
			{
				Q.push(cur - 1);
				visit[cur - 1] = 1;
				p[cur - 1] = cur;
			}
			
			if (cur < 100000 && !visit[cur + 1])
			{
				Q.push(cur + 1);
				visit[cur + 1] = 1;
				p[cur + 1] = cur;
			}

			if (cur <= 50000 && !visit[cur * 2])
			{
				Q.push(cur * 2);
				visit[cur * 2] = 1;
				p[cur * 2] = cur;
			}

		}
		
		count++;
	}
}