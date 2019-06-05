#include <cstdio>
#include <queue>
#include <bitset>
#include <algorithm>
using namespace std;

int main()
{
	int bg[3], cur[3], sum;
	scanf("%d %d %d", bg, bg + 1, bg + 2);
	sum = bg[2];
	bitset<201> v[201], ans;
	queue<int> Q;
	v[0][0] = 1;
	Q.push(0);
	while (Q.size())
	{
		int s = Q.front();
		Q.pop();

		cur[0] = s / 300, s %= 300;
		cur[1] = s;
		cur[2] = sum - cur[0] - cur[1];
		if (!cur[0] && !ans[cur[2]])
			ans[cur[2]] = 1;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == j)
					continue;

				if (cur[i] > 0 && cur[j] < bg[j])
				{
					int n[3] = { cur[0], cur[1], cur[2] };
					int l = min(n[i], bg[j] - n[j]);

					n[i] = cur[i] - l, n[j] = cur[j] + l;
					l = n[0] * 300 + n[1];
					if (!v[n[0]][n[1]])
					{
						v[n[0]][n[1]] = 1, Q.push(l);
					}
				}
			}
		}
	}

	for (int i = 0; i < 201; i++)
		if (ans[i])
			printf("%d ", i);
}
