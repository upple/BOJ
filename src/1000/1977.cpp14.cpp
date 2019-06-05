#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	int m, n, sum = 0, min = -1;
	scanf("%d %d", &m, &n);

	for (int i = n; i >= m; i--)
	{
		if ((int)sqrt(i)*(int)sqrt(i) == i)
			sum += i, min = i;
	}

	if (min == -1)
		printf("%d", min);

	else
		printf("%d\n%d\n", sum, min);

	return 0;
}
