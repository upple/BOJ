#include <cstdio>

bool arr[20000001];

int main()
{
	int n, m, num;
	scanf("%d", &n);

	while (n--)
	{
		scanf("%d", &num);
		arr[num + 10000000] = 1;
	}

	scanf("%d", &m);
	while (m--)
	{
		scanf("%d", &num);
		printf("%d ", arr[num+10000000]);
	}
}