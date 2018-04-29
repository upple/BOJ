#include <cstdio>

typedef long long ll;

int main()
{
	ll n, m;
	ll arr[100000];
	scanf("%lld %lld", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%lld", arr + i);

	ll min = 1, max = 1000000000000000;
	ll mid = (min + max) / 2, ans = max;
	while (min <= max)
	{
		ll cur = m;
		for (int i = 0; i < n; i++)
		{
			ll p = mid / arr[i];

			cur -= p;
			if (cur <= 0)
				break;
		}

		if (cur > 0)
			min = mid + 1;

		else
		{
			if (ans > mid)
				ans = mid;

			max = mid - 1;
		}

		mid = (min + max) / 2;
	}

	printf("%lld", ans);
}