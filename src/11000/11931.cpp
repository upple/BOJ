#include <cstdio>
#include <algorithm>
int main()
{
	int n;
	int arr[1000000];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	std::sort(arr, arr + n);

	for (int i = n - 1; i >= 0; i--)
		printf("%d\n", arr[i]);
}