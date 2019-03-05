#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	long long n, m, ans;
	scanf("%lld %lld", &n, &m);
	ans = n - m;
	if (ans < 0)
		ans *= -1;
	printf("%lld", ans);
	return 0;

}
