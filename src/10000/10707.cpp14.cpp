#include<iostream>

using namespace std;

int main()
{
	int a, b, c, d, p, X, Y;
	cin >> a >> b >> c >> d >> p;

	X = a*p;
	if (p > c)
		Y = b + d*(p - c);

	else
		Y = b;

	cout << (X > Y ? Y : X) << endl;
	return 0;
}