#include <iostream>
#include <queue>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		priority_queue<ll> pq;
		int n;
		ll ans = 1;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			ll num;
			cin >> num;
			pq.push(-num);
		}

		while (pq.size() > 1)
		{
			ll a, b;
			a = -pq.top(), pq.pop();
			b = -pq.top(), pq.pop();

			ans = (ans * ((a*b) % MOD)) % MOD;
			pq.push(-(a*b));
		}

		cout << ans << "\n";
	}
}