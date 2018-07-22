#include<cstdio>
using namespace std;

int main()
{
	int t, n;
	scanf("%d", &t);

	while (t--)
	{
		int ans;
		scanf("%d %d", &ans, &n);
		while (n--)
		{
			int num, cost;
			scanf("%d %d", &num, &cost);
			ans += num*cost;
		}

		printf("%d\n", ans);
	}
}
