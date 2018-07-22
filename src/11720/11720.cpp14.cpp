#include<cstdio>

int main()
{
	int no_case, sum=0;
	char num;
	scanf("%d ", &no_case);
	while (no_case--)
	{
		scanf("%c", &num);
		sum += num - '0';
	}

	printf("%d", sum);
	return 0;
}