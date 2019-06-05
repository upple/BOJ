#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;
ll arr[100];

ll GCD(ll a, ll b)
{
	if (a > b) swap(a, b);
	if (a == 0) return b;
	return GCD(b%a, a);
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
	ll gcd = arr[1] - arr[0];
	for (int i = 2; i < n; i++)
		gcd = GCD(arr[i] - arr[0], gcd);

	set<ll> ans;
	for (ll i = 2; i*i <= gcd; i++)
	{
		if (!(gcd%i))
			ans.insert(i), ans.insert(gcd / i);
	}

	ans.insert(gcd);
	for (ll i : ans) cout << i << " ";
}