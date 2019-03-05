#include <cstdio>
#include <algorithm>
int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int m, n, x, y;
		scanf("%d %d %d %d", &m, &n, &x, &y);
		if (m > n)
			std::swap(m, n), std::swap(x, y);

		int ty = 1, count = 1;
		while (1)
		{
			if (1 - ty == x - y || 1 - ty + n == x - y)
			{
				printf("%d\n", count + x - 1);
				goto out;
			}
			if (1 - ty == m - n)
				break;

			count += m, ty += m;
			if (ty > n)
				ty %= n;
		}

		printf("-1\n");
	out:;
	}
}