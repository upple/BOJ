#include <iostream>
#include <cmath>
#define MAX 500000
using namespace std;

int n, s;
int M[1000001];
int st[4 * MAX];
long long ans;
void update(int p)
{
	p += s;
	while (p)
	{
		st[p]++;
		p >>= 1;
	}
}

long long query(int l, int r, int p, int x, int y)
{
	if (l > y || r < x) return 0;
	if (l <= x && r >= y) return st[p];
	int mid = (x + y) >> 1;
	return query(l, r, p << 1, x, mid) + query(l, r, (p << 1) + 1, mid + 1, y);
}
int main()
{
	cin >> n;
	s = 1 << int(ceil(log2(n)));

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		M[x] = i;
	}

	for (int i = 0; i < n; i++)
	{
		int x, it;
		cin >> x;
		it = M[x];
		ans += query(it, n - 1, 1, 0, s - 1);
		update(it);
	}
	cout << ans;
}