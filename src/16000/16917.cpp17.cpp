#include <iostream>
#include <algorithm>
const int INF=1e9;
using namespace std;

int main()
{
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int r1, r2, r3;
	r1 = min(x, y) * 2 * c + abs(x - y)*(x > y ? a : b);
	r2 = x*a + y*b;
	r3 = max(x, y) * 2 * c;
	cout << min({ r1, r2, r3 });
}