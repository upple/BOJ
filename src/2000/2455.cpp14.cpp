#include <cstdio>
#define max(x, y) ((x)>(y)?(x):(y))
using namespace std;

int main()
{
	int t, l, ans=0, left=0;
	for (int i = 0; i < 4; i++)
	{
		scanf("%d %d", &l, &t);
		left += t - l;
		ans = max(ans, left);
	}

	printf("%d\n", ans);
	return 0;
}
