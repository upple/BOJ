#include <cstdio>
#include <algorithm>

int arr[10002];
int main()
{
	int n, num, ans = 0;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &num);
		arr[i] = num;
	}

	arr[0] = -1, arr[n + 1] = 10001;
	std::sort(arr + 1, arr + n + 1);
    
	for (int i = 0; i <= n; i++)
	{
		if ((arr[n - i + 1] >= i) && (arr[n - i] <= i))
			ans = i;
	}

	printf("%d", ans);
}