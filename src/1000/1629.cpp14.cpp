#include <cstdio>

using namespace std;
typedef long long(ll);

ll mult(ll a, ll b, ll c)
{
	if (b == 0)
		return 1;

	if (b == 1)
		return a%c;

	if (b % 2)
		return mult(a*a%c, b / 2, c)*a%c;

	else
		return mult(a*a%c, b / 2, c);
}

int main()
{
	ll a, b, c;
	scanf("%lld %lld %lld", &a, &b, &c);
	printf("%lld\n", mult(a, b, c));
	return 0;
} 