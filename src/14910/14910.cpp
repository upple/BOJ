#include <cstdio>

int main()
{
	int num, cur, s;
	scanf("%d", &cur);
	s = cur;
	while (scanf("%d", &num) != EOF)
	{
		if (num < cur)
		{
			printf("Bad");
			return 0;
		}
		cur = num;

	}

	printf("Good");
}