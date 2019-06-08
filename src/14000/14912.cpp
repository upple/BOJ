#include <cstdio>

int main()
{
	int n, d, ans=0;
	scanf("%d %d", &n, &d);

	for (int i = 1; i <= n; i++)
	{
		int tmp = i;
		while (tmp)
		{
			if (tmp % 10 == d)
				ans++;

			tmp /= 10;
		}
	}

	printf("%d", ans);
}