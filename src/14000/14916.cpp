#include <cstdio>

int main()
{
	int n, a;
	scanf("%d", &n);

	a = n / 5;
	n %= 5;
	if (n % 2)
	{
		if (a == 0)
			printf("-1");

		else
			printf("%d", a - 1 + (n + 5) / 2);
	}

	else
		printf("%d", a + n / 2);
}