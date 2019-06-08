#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;
priority_queue<ll> pq;
int main()
{
	int n, m;
	ll a;
	cin >> n >> m;
	for (int i = 0; i<n; i++)
	{
		cin >> a;
		pq.push(-a);
	}
	while (m--)
	{
		ll x, y;
		x = pq.top(), pq.pop();
		y = pq.top(), pq.pop();
		pq.push(x + y), pq.push(x + y);
	}
	ll ans = 0;
	while (pq.size())
	{
		ans -= pq.top();
		pq.pop();
	}
	cout << ans;
}