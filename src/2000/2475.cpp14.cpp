#include<cstdio>
#define SQRT(x) x*x

using namespace std;

int main()
{
	int ans=0, n;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &n);
		ans += SQRT(n);
	}

	printf("%d\n", ans % 10);
	return 0;
}
