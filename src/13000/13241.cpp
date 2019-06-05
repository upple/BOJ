#include <cstdio>
#include <algorithm>
typedef long long ll;

ll gcd(ll a, ll b)
{
	if (a < b)
		std::swap(a, b);

	while (a)
	{
		ll tmp = b % a;
		b = a;
		a = tmp;
	}

	return b;
}
int main()
{
	ll a, b, m;
	scanf("%lld %lld", &a, &b);

	m = gcd(a, b);
	printf("%lld", (a / m)*b);
}