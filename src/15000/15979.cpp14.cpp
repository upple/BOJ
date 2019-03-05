#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
	while (a)
	{
		int t = b;
		b = a;
		a = t % a;
	}

	return b;
}
int main()
{
	int a, b;
	cin >> a >> b;
	a = abs(a), b = abs(b);
	if (a == 0 && b == 0)
	{
		cout << 0;
		return 0;
	}
	if (a > b) std::swap(a, b);
	cout << (gcd(a, b) == 1 ? 1 : 2);
}