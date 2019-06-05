#include <stdio.h>

int main()
{
	while (1)
	{
		double a, b, c;
		int ans;
		scanf("%lf %lf %lf", &a, &b, &c);

		if (a == b)
			return 0;

		if (b / a == c / b)
			printf("GP %.0lf\n", c * (b / a));

		else
			printf("AP %.0lf\n", c + (b - a));
	}
}