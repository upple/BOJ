#include <cstdio>
using namespace std;

int main()
{
	int t, n;
	long long ans, v;
	scanf("%d", &t);
	while(t--)
	{
		ans=0;
		scanf("%d", &n);
		while(n--)
		{
			scanf("%lld", &v);
			ans+=v;
		}

		printf("%lld\n", ans);
	}
}
