#include<cstdio>

using namespace std;

int gcd(int a, int b)
{
	int temp;
	while (1)
	{
		if (a%b == 0)
			return b;

		temp = a;
		a = b;
		b = temp%b;
	}
}
int main()
{
	int a, b, c, d;
	int x, y, divide;
	scanf("%d %d %d %d", &a, &b, &c, &d);

	x = a*d + b*c;
	y = b*d;
	divide = gcd(x, y);
	printf("%d %d\n", x / divide, y / divide);
	return 0;
}