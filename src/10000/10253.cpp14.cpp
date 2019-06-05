#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
ll gcd(ll a, ll b)
{
	if (a > b) swap(a, b);
	if (a == 0) return b;
	return gcd(b%a, a);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		ll n, m;
		cin >> n >> m;
		while (n != 0)
		{
			ll di = gcd(n, m);
			n /= di, m /= di;
			ll tmpm = m / n + (m % n != 0), tmpn = 1;
			ll gcdd = gcd(m, tmpm);
			tmpn *= m / gcdd;
			n *= tmpm / gcdd;
			n -= tmpn;
			m *= tmpm / gcdd;
		}

		cout << m << "\n";
	}
}