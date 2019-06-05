#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int n, ans1, ans2;
	int arr[10000];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	if (n == 2)
	{
		printf("%d", arr[0] + arr[1]);
		return 0;
	}

	sort(arr, arr + n);
	ans1 = max(arr[0] * arr[1], arr[n - 1] * arr[n - 2]);
	ans2 = max(arr[0] * arr[1] * arr[n-1], arr[n - 1] * arr[n - 2] * arr[n - 3]);
	

	printf("%d", max(ans1, ans2));
}