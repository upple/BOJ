#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 75000
using namespace std;

int st[4 * MAX], ay[MAX];
pair<int, int> arr[MAX];
int n, c, s, t;

int query(int l, int r, int p, int x, int y)
{
	if (l > y || r < x) return 0;
	if (l <= x && r >= y) return st[p];
	int mid = (x + y) >> 1;
	return query(l, r, p << 1, x, mid) + query(l, r, (p << 1) + 1, mid + 1, y);
}
void update(int x)
{
	x += c;
	while (x)
	{
		st[x] += 1;
		x >>= 1;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--)
	{
		cin >> n;
		c = n, s = 1;
		if ((c&-c) != c)
		{
			while (c != 1) c >>= 1, s++;
			c <<= s;
		}
		memset(st, 0, c * 8);
		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			arr[i] = { x, -y };
			ay[i] = -y;
		}

		sort(arr, arr + n);
		sort(ay, ay + n);

		long long ans = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			int it = lower_bound(ay, ay + n, arr[i].second) - ay;
			ans += query(it, n - 1, 1, 0, c - 1);
			update(it);
		}
		cout << ans << "\n";
	}
}