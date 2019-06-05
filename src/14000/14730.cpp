#include <cstdio>

int main()
{
	int n, ans=0;
	scanf("%d", &n);

	while(n--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if(b)
			ans+=a*b;
	}

	printf("%d", ans);
}
