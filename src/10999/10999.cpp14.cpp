#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 1000000
using namespace std;
typedef long long ll;

ll st[4*MAX], lazy[4*MAX];
int n, m, k, s;
ll init(int p)
{
	if (p >= s) return st[p];
	return st[p] = init(p << 1) + init((p << 1) + 1);
}

void lazy_update(int len, int p)
{
	if (lazy[p])
	{
		st[p] += lazy[p] * len;
		if (p < s)
		{
			lazy[p << 1] += lazy[p];
			lazy[(p << 1) + 1] += lazy[p];
		}
	}

	lazy[p] = 0;
}

ll query(int l, int r, int p, int x, int y)
{
	lazy_update(y - x + 1, p);
	if (l > y || r < x) return 0;
	if (l <= x && r >= y) return st[p];
	int mid = (x + y) >> 1;
	return query(l, r, p << 1, x, mid) + query(l, r, (p << 1) + 1, mid + 1, y);
}

void range_update(int l, int r, int p, int x, int y, ll c)
{
	lazy_update(y - x + 1, p);
	if (l > y || r < x) return;
	if (l <= x && r >= y)
	{
		lazy[p] += c;
		lazy_update(y - x + 1, p);
		return; 
	}
	int mid = (x + y) >> 1;
	range_update(l, r, p << 1, x, mid, c);
	range_update(l, r, (p << 1) + 1, mid + 1, y, c);
	st[p] = st[p << 1] + st[(p << 1) + 1];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	s = 1 << int(ceil(log2(n)));

	for (int i = 0; i < n; i++)
		cin >> st[s + i];

	init(1);

	int z = m + k;
	while (z--)
	{
		int a, b, c;
		ll d;
		cin >> a >> b >> c;
		if (b > c) swap(b, c);

		if (a == 2)
		{
			cout << query(b - 1, c - 1, 1, 0, s - 1) << "\n";
		}
		else
		{
			cin >> d;
			range_update(b - 1, c - 1, 1, 0, s - 1, d);
		}
	}

}