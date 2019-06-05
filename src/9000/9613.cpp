#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long ll;
inline ll gcd(ll a, ll b)
{
	if (b > a)
		swap(a, b);
	while (b)
	{
		ll temp = a;
		a = b, b = temp % b;
	}
	return a;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		ll ans = 0, arr[100];
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%lld", &arr[i]);

		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				ans += gcd(arr[i], arr[j]);

		printf("%lld\n", ans);
	}

}
