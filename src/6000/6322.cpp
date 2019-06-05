#include <cstdio>
#include <cmath>

int main()
{
	double a, b, c;
	int num = 0;
	while (++num)
	{
		scanf("%lf %lf %lf", &a, &b, &c);
		if (a == 0)
			return 0;
		
		printf("Triangle #%d\n", num);
		if (a == -1)
		{
			if (c <= b)
				printf("Impossible.");

			else
				printf("a = %.3lf", sqrt(c*c - b*b));
		}
		else if (b == -1)
		{
			if (c <= a)
				printf("Impossible.");

			else
				printf("b = %.3lf", sqrt(c*c - a*a));
		}
		else
			printf("c = %.3lf", sqrt(a*a + b*b));

		printf("\n\n");
	}
}