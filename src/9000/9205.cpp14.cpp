#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct xy
{
	int x, y;
};
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		xy start, dest, arr[100];
		int n, visit[100] = {};
		queue<xy> Q;
		scanf("%d", &n);
		scanf("%d %d", &start.x, &start.y);

		for (int i = 0; i < n; i++)
			scanf("%d %d", &arr[i].x, &arr[i].y);

		scanf("%d %d", &dest.x, &dest.y);

		Q.push(start);
		while (Q.size())
		{
			xy cur = Q.front();
			Q.pop();

			if (abs(dest.x - cur.x) + abs(dest.y - cur.y) <= 1000)
			{
				printf("happy\n");
				goto out;
			}
			
			for (int i = 0; i < n; i++)
			{
				if (visit[i] || abs(arr[i].x-cur.x)+abs(arr[i].y-cur.y)>1000)
					continue;

				visit[i] = 1, Q.push(arr[i]);
			}
		}

		printf("sad\n");
	out:;
	}
}