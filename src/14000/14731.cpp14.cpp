#include <cstdio>
#define MOD 1000000007
typedef long long ll;

ll solve(ll a, ll b)
{
	ll mul = 2;
	a = a*b%MOD, b--;
	if (b <= 0)
		return a;

	while (b != 1)
	{

		if (b % 2)
			a = a * mul % MOD;

		mul = (mul*mul) % MOD;
		b /= 2;
	}

	return a*mul%MOD;
}

int main()
{
	int n;
	ll ans = 0;
	scanf("%d", &n);
	while (n--)
	{
		ll a, b;
		scanf("%lld %lld", &a, &b);
		ans = (ans + solve(a, b)) % MOD;
	}

	printf("%lld", ans);
}