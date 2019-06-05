#include <cstdio>
#include <cmath>
using namespace std;

int inline getI(int x, int num)
{
	return num%(int)pow(10, x)/(int)pow(10, x-1);
}
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	for(int i=1; i<=3; i++)
		printf("%d\n", a*getI(i, b));

	printf("%d\n", a*b);
	return 0;
}
