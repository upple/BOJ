#include <cstdio>

int main()
{
	int arr[31] = {}, num;
	for (int i = 0; i < 28; i++)
	{
		scanf("%d", &num);
		arr[num] = 1;
	}

	for (int i = 1; i <= 30; i++)
	{
		if (arr[i] == 0)
			printf("%d\n", i);
	}
}