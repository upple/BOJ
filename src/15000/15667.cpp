#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		if (i*i + i + 1 - n == 0)
		{
			printf("%d", i);
			return 0;
		}
	}
}