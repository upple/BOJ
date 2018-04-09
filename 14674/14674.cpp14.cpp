#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<pair<ll, ll>, pair<ll, int> > STRT;
bool sortFunc(STRT &a, STRT &b)
{
	ll x, y;
	x = a.first.first*b.first.second;
	y = b.first.first*a.first.second;
	if (x != y)
		return x > y;
	
	if (a.first.second != b.first.second)
		return a.first.second < b.first.second;

	else
		return a.second.second < b.second.second;
}
int main()
{
	int n, k;
	STRT arr[1001];
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		int num;
		ll c, f;
		scanf("%d %lld %lld", &num, &c, &f);
		arr[num] = { {f, c} ,{ c, num } };
	}
	sort(arr + 1, arr + n + 1, sortFunc);
	for (int i = 1; i <= k; i++)
		printf("%d\n", arr[i].second.second);
}
