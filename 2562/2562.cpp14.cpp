#include<cstdio>

int main()
{
	int max=0, num, pos;

	for (int i = 1; i < 10; i++)
	{
		scanf("%d", &num);
		if (num > max)
			max = num, pos = i;
	
	}

	printf("%d\n%d\n", max, pos);
	return 0;
}