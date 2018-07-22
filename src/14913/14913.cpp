#include <cstdio>

int main()
{
	int a, d, x;
	scanf("%d %d %d", &a, &d, &x);
	x -= a;
	if (x%d || x * d < 0)
		printf("X");

	else
		printf("%d", x / d + 1);
}