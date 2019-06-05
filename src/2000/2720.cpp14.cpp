#include<cstdio>

int main()
{
	int no_case;
	scanf("%d", &no_case);
	while (no_case--)
	{
		int q, d, n, p, money;

		scanf("%d", &money);

		q = money / 25, money %= 25;
		d = money / 10, money %= 10;
		n = money / 5,  money %= 5;
		p = money / 1,  money %= 1;

		printf("%d %d %d %d\n", q, d, n, p);
	}
	
	return 0;
}