#include <cstdio>
#define max(x, y) (x>y?x:y)
int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n, ans=0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			ans += max(max(a, b), max(c, 0));
		}

		printf("%d\n", ans);
	}
}