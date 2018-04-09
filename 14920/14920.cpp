#include <cstdio>

int main()
{
	long long cnt = 1, c;
	scanf("%lld", &c);
	while (c != 1)
	{
		c = (c % 2 ? c * 3 + 1 : c / 2);
		cnt++;
	}

	printf("%lld", cnt);
}