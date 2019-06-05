#include <cstdio>

int main()
{
	double fact = 2, ans=2.5;

	printf("n e\n- -----------\n0 1\n1 2\n2 2.5\n");
	for (double i = 3; i < 10; i += 1)
	{
		fact *= i;
		ans += 1 / fact;
		printf("%d %.9lf\n", (int)i, ans);
	}
}