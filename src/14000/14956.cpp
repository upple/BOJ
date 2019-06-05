#include <cstdio>
#include <cmath>
#include <algorithm>
typedef long long ll;
ll n, m;
void solve(int &x, int &y, ll start, ll size)
{
	if (start == m)
		return;

	size /= 2;
	ll sqare = (ll)pow(size, 2);
	ll next_start = start + sqare * ((m - start) / sqare);
	solve(x, y, next_start, size);
	switch ((m - start) / sqare)
	{
	case 0:
		std::swap(x, y); break;
	case 2:
		x += size;
	case 1:
		y += size; break;
	case 3:
		std::swap(x, y);
		x = 2 * size - x - 1;
		y = size - y - 1;
		break;
	}
}
int main()
{
	scanf("%lld %lld", &n, &m);
	m--;
	int x = 0, y = 0;
	solve(x, y, 0, n);

	printf("%d %d", x + 1, y + 1);
}