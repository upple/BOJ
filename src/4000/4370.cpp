#include <cstdio>

int main()
{
	long long n;
	while (scanf("%lld", &n) != EOF)
	{
		int p = 1;
		while (p * 18 < n)
			p *= 18;

		long long div = n / p + (n%p!=0);
		printf("%s wins.\n", div > 9 ? "Donghyuk" : "Baekjoon");
	}
}