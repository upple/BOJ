#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

struct xyr
{
	int x, y, r;
};

bool isInside(xyr &a, xyr &b)
{
	return (int)pow(a.r+b.r, 2)>=((int)pow((a.x - b.x), 2) + (int)pow(a.y - b.y, 2));
}
int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n, ans=0;
		int visit[3000] = {};
		xyr arr[3000];
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			int x, y, r;
			scanf("%d %d %d", &x, &y, &r);

			arr[i] = { x, y, r };
		}

		for (int i = 0; i < n; i++)
		{
			if (visit[i])
				continue;

			visit[i]=1, ans++;
			queue<int> Q;
			Q.push(i);
			while (Q.size())
			{
				int cur = Q.front();
				Q.pop();
				for (int j = 0; j < n; j++)
				{
					if (!visit[j] && isInside(arr[cur], arr[j]))
						visit[j] = 1, Q.push(j);
				}
			}
		}

		printf("%d\n", ans);
	}
}