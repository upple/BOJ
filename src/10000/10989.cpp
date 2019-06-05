#include <cstdio>
int main()
{
	int arr[10001] = {};
	int n, num;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		arr[num]++;
	}

	for (int i = 1; i <= 10000; i++)
	{
		int j = arr[i];
		while (j--)
			printf("%d\n", i);
	}
}