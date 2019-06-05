#include <cstdio>
#define max(x, y) x>y?x:y

int solve(int x)
{
	int num = x;
	while (num)
	{
		x += num % 10;
		num /= 10;
	}

	return x;
}
int main()
{
	int n;
	scanf("%d", &n);

	for (int i = max(1, n - 54); i <= n; i++)
	{
		if (n == solve(i))
		{
			printf("%d", i);
			return 0;
		}
	}

	printf("0");
}