#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);
	for(int i=1; i<=t; i++)
	{
		long long n, m;
		scanf("%lld %lld", &n, &m);

		printf("Scenario #%d:\n", i);
		if ((m - n) % 2)
			printf("%lld\n\n", (m + n)*((m - n) / 2 + 1));

		else
			printf("%lld\n\n", (m + n) / 2 * ((m - n) + 1));

	}
}