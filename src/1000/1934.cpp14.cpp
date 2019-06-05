#include<cstdio>
using namespace std;

int main()
{
	int no_case, a, b;
	scanf("%d", &no_case);
	while (no_case--)
	{
		scanf("%d %d", &a, &b);
		int temp = a;
		while (1)
		{
			if (a%b == 0)
				break;

			a += temp;
		}

		printf("%d\n", a);

	}
	return 0;
}
