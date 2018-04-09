#include <cstdio>

int main()
{
	long long n, ans = 0;
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
	{
		if (n%i == 0)
			ans += i;
	}

	printf("%lld", ans * 5 - 24);
}