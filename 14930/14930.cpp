#include <cstdio>
#include <algorithm>

typedef long long ll;
ll arr[100000];
int main()
{
	ll n, t, x, v, s, it = 0;
	scanf("%lld %lld %lld %lld", &n, &t, &x, &v);
	s = x, arr[0] = x + (v*t);
	for (ll i = 1; i < n; i++)
	{
		scanf("%lld %lld", &x, &v);
		if (x < s)
			it++;

		arr[i] = x + (v*t);
	}

	std::sort(arr, arr + n);
	printf("%lld", arr[it]);	
}