#include <cstdio>

typedef long long ll;
int main()
{
	ll a, b;
	int ans;
	bool arr[1000002] = {};
	scanf("%lld %lld", &a, &b);
	ans = b - a + 1;
	for (ll i = 2; i*i <= b; i++)
	{
		ll temp = a / (i*i);
		if (a%(i*i))
			temp ++;

		temp = temp*(i*i) - a;
		while (temp <= b - a)
		{
			if (!arr[temp])
				ans--, arr[temp] = true;

			temp += i*i;
		}

	}
	printf("%d", ans);

}
