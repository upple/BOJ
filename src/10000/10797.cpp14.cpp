#include<cstdio>
#define min(x, y) (x<y?x:y)
using namespace std;
int main()
{
	int d, n, ans=0;
	scanf("%d", &d);
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &n);
		if (n == d)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}	