#include <cstdio>
#define MOD 1000000000;
int n;
long long a, b, c;
int main()
{
	scanf("%d", &n);

	a = 0, b = 1;
	for (int i = 2; i < n; i++)
	{
		c = (i * (a + b))%MOD;
		a = b;
		b = c;
	}

	printf("%lld", n==1?0:b);
}