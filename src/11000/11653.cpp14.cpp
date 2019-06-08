#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	while (n != 1)
	{
		static int d = 2;
		if (!(n%d))
			printf("%d\n", d), n /= d;

		else
			d++;
	}
}