#include <cstdio>

int main()
{
	int n, m;
	int arr[1001] = {};

	scanf("%d %d", &n, &m);

	while (m--)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		arr[a]++, arr[b]++;
	}

	for (int i = 1; i <= n; i++)
		printf("%d\n", arr[i]);
}