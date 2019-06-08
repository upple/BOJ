#include <cstdio>
#include <queue>
using namespace std;
int main()
{
	int f, s, g, u, d, count=0;
	bool visit[1000001] = {};
	queue<int> Q;
	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

	Q.push(s), Q.push(-1);
	visit[s] = true;

	while (Q.size())
	{
		int cur = Q.front();
		Q.pop();

		if (cur == -1)
		{
			if (Q.empty())
			{
				printf("use the stairs");
				return 0;
			}

			count++, Q.push(-1);
			continue;
		}

		if (cur == g)
		{
			printf("%d", count);
			return 0;
		}

		if (cur + u <= f && !visit[cur + u])
			visit[cur + u] = true, Q.push(cur + u);

		if (cur - d > 0 && !visit[cur - d])
			visit[cur - d] = true, Q.push(cur - d);
	}
}