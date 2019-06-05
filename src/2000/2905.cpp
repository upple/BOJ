#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAX 1000000
using namespace std;
typedef long long ll;
int tree[4 * MAX];
int n, x, s;

void update(int p)
{
	p += s;
	int y = tree[p];
	while (p)
	{
		if (!tree[p]) tree[p] = y;
		else tree[p] = min(tree[p], y);
		p >>= 1;
	}
}

int query(int l, int r, int p, int x, int y)
{
	if (l > y || r < x || !tree[p]) return MAX;
	if (l<=x && r>=y) return tree[p];
	int mid = (x + y) >> 1;
	return min(query(l, r, p << 1, x, mid), query(l, r, (p << 1) + 1, mid + 1, y));
}
int main()
{
	scanf("%d %d", &n, &x);
	ll sum = 0, ans = 0;
	s = 1 << int(ceil(log2(n)));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tree[s + i]);
		update(i);
		sum += tree[s + i];
	}
	int cur = 0, ov = 0, cnt = 0;
	for (int i = 0; i <= n - x; i++)
	{
		int lo = query(i, i + x - 1, 1, 0, s - 1);
		if (cur < lo)
		{
			sum -= lo * x - (ov*cur);
			ov = x;
			cur = lo;
			cnt++;
		}
		else if (cur >= lo && (i + x == n || tree[s + i + x] < lo))
		{
			sum -= lo * (x - ov);
			ov = x;
			cur = lo;
			cnt++;
		}

		ov = max(0, ov - 1);
		if (ov == 0) cur = 0;
	}

	printf("%lld\n%d", sum, cnt);
}