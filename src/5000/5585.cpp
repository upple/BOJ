#include <cstdio>

int main()
{
	int coin[] = { 500, 100, 50, 10, 5, 1 };
	int ans = 0, n;
	scanf("%d", &n);
	n = 1000 - n;
	for (int i = 0; i < 6; i++)
		ans += (n / coin[i]), n %= coin[i];

	printf("%d", ans);
}
