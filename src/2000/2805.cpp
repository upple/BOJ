#include <cstdio>
#include <algorithm>
using namespace std;

int n, arr[1000000];
int bs(int left, int right, int x)
{
	int mid = (left + right) / 2;

	while (left <= right)
	{
		long long sum = 0;
		for (int i = 0; i<n; i++)
		{
			sum += max(arr[i] - mid, 0);

			if (sum >= x)
				break;
		}

		if (sum >= x)
			left = mid + 1;

		else
			right = mid - 1;

		mid = (left + right) / 2;
	}

	return mid;
}

int main()
{
	int m, min = 1111111111, max = 0;
	scanf("%d %d", &n, &m);

	for (int i = 0; i<n; i++)
	{
		scanf("%d", &arr[i]);

		if (arr[i]>max)
			max = arr[i];
	}

	printf("%d", bs(0, max, m));
}
