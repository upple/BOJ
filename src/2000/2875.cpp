#include <cstdio>

int main()
{
	int n, m, k, ans;
	scanf("%d %d %d", &n, &m, &k);

	ans = (n > m * 2 ? m : n/2);
	printf("%d", (ans < (n + m - k) / 3 ? ans : (n + m - k) / 3));
}