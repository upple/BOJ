#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int inline GCD(int a, int b)
{
	if (b > a)
		swap(a, b);

	while (a%b!=0)
	{
		int temp = a;
		a = b;
		b = temp % b;
	}

	return b;
}

int main()
{
	int a, b, gcd;
	scanf("%d %d", &a, &b);
	gcd = GCD(a, b);
	printf("%d %d\n", gcd, a*b/gcd);
}
