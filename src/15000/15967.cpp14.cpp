#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 1000001
using namespace std;
typedef long long ll;

ll st[MAX], lazy[MAX];
int n, m, l, s;
ll init(int p)
{
	if (p >= s) return st[p];
	return st[p] = init(p << 1) + init((p << 1) + 1);
}

void lazy_update(int l, int r, int p)
{
	if (lazy[p])
	{
		st[p] += (r - l + 1)*lazy[p];
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
	lazy_update(l, r, p);
	if (l > y || r < x) return 0;
	if (l <= x && r >= y) return st[p];
	int mid = (x + y) >> 1;
	return query(l, r, p << 1, x, mid) + query(l, r, (p << 1) + 1, mid + 1, y);
}

ll range_update(int l, int r, int p, int x, int y, ll c)
{
	lazy_update(l, r, p);
	if (l > y || r < x) return 0;
	if (l <= x && r >= y)
	{
		st[p] += (r - l + 1)*c;
		if (p < s)
		{
			lazy[p << 1] += c;
			lazy[(p << 1) + 1] += c;
		}
		return st[p];
	}
	int mid = (x + y) >> 1;
	return st[p] = range_update(l, r, p << 1, x, mid, c) + range_update(l, r, (p << 1) + 1, mid + 1, y, c);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> l;
	s = 1 << int(ceil(log2(n)));

	for (int i = 0; i < n; i++)
		cin >> st[s + i];

	init(1);

	int z = m + l;
	while (z--)
	{
		int a, b, c;
		long long d;
		cin >> a >> b >> c;
		if (a == 1)
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