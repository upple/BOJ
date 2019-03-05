#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
typedef long long ll;
bitset<10000001> arr;
vector<ll> prime;
int main()
{
	ll a, b, ans = 0;
	cin >> a >> b;

	for (ll i = 2; i*i <= b; i++)
	{
		if (!arr[i])
		{
			prime.push_back(i);
			ll tmp = i + i;
			while (tmp <= b / tmp)
			{
				arr[tmp] = 1;
				tmp += i;
			}
		}
	}
	
	for (ll p : prime)
	{
		ll tmp = p;
		while (tmp <= b / p)
		{
			tmp *= p;
			if (tmp >= a)
				ans++;

		}
	}

	cout << ans;
}