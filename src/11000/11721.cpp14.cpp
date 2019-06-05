#include<cstdio>

int main()
{
	char temp, count=0;
	while (scanf("%c", &temp) != EOF)
	{
		printf("%c", temp);
		if (++count == 10)
			printf("\n"), count = 0;
	}

	return 0;
}