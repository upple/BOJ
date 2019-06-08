#include <cstdio>
#include <algorithm>

int arr[10000];
int main()
{
	int n, k, ans;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	std::sort(arr, arr + n);
	ans = arr[n - 1] - arr[0];
	for (int i = 0; i < n - 1; i++)
	{
		arr[i] = arr[i + 1] - arr[i];
	}

	std::sort(arr, arr + n - 1);

	if (k >= n - 1)
	{
		puts("0");
		return 0;
	}

	for (int i = 1; i < k; i++)
		ans -= arr[n - i - 1]; 

	printf("%d", ans);
	
}