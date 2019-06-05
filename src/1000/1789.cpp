#include <cstdio>

int main()
{
	long long n, i;
	scanf("%lld", &n);
	for (i = 0; i < n; n -= ++i);

	printf("%lld", i);
}