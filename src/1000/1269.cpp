#include <cstdio>
#include <algorithm>

int arr[200000];
int main()
{
	int n, m, num, ans;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	ans = n;
	std::sort(arr, arr + n);

	while (m--)
	{
		scanf("%d", &num);
		ans += (std::binary_search(arr, arr + n, num) ? -1 : 1);
	}

	printf("%d", ans);
}