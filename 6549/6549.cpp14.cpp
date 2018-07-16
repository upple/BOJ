#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
long long n, s, c;
long long arr[400001];

long long solve(long long l, long long r, long long x)
{
	if (arr[x] || x >= c) return arr[x];
	long long mid = (l + r) / 2;
	long long ll = mid - 1, rr = mid + 1, res = arr[c + mid], h = arr[c + mid];
	while (ll >= l || rr <= r)
	{
		if (ll < l || rr <= r && arr[c + rr] > arr[c + ll]) h = min(h, arr[c + rr++]);
		else h = min(h, arr[c + ll--]);

		res = max(res, h*(rr - ll - 1));
	}
	return arr[x] = max({ res, solve(l, mid, x * 2), solve(mid + 1, r, x * 2 + 1) });
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (1)
	{
		cin >> n;
		if (n == 0) return 0;
		c = n, s = 0;
		if ((c&-c) != c)
		{
			while (c != 1) c >>= 1, s++;
			c = c << (s + 1);
		}
		memset(arr, 0, c * 2 * 8);
		for (long long i = 0; i < n; i++)
		{
			cin >> arr[i + c];
		}
		cout << solve(0, c - 1, 1) << "\n";
	}
}