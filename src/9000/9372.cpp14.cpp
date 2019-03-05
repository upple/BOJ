#include <cstdio>

int main()
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		int n, m, a, b;
		scanf("%d %d", &n, &m);

		while(m--)
			scanf("%d %d", &a, &b);

		printf("%d\n", n-1);
	}
}
