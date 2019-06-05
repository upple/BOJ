#include <iostream>
#include <cmath>
#include <cstring>
#define MAX 200000
using namespace std;

int st[4 * MAX], p[MAX + 1];

int n, m, s;
void update(int p, int x)
{
	p += s;
	while (p)
	{
		st[p] += x;
		p >>= 1;
	}
}

int query(int l, int r, int p, int x, int y)
{
	if (l > y || r < x) return 0;
	if (l <= x && r >= y) return st[p];
	int mid = (x + y) >> 1;
	return query(l, r, p << 1, x, mid) + query(l, r, (p << 1) + 1, mid + 1, y);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		s = 1 << int(ceil(log2(n + m)));
		memset(st, 0, s * 8);
		memset(p, 0, s * 4);
		for (int i = 0; i < n; i++)
		{
			p[n - i] = i;
			update(i, 1);
		}
		int it = 0;
		while (m--)
		{
			int x;
			cin >> x;
			update(p[x], -1);
			cout << query(p[x], s - 1, 1, 0, s - 1) << " ";
			p[x] = n + it++;
			update(p[x], 1);
		}
		cout << "\n";
	}

}