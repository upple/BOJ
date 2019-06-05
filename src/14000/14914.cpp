#include <cstdio>
#include <cmath>
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);

	for (int i = 1; i <=a; i++)
	{
		if (a%i == 0 && b%i == 0)
		{
			printf("%d %d %d\n", i, a/i, b/i);
		}

	}
}