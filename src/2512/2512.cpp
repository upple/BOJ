#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, arr[100000];

int bs(int right)
{
	int left = 1, mid = (1+right)/2, ans;
	while (left <= right)
	{
		int sum = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			sum += min(arr[i], mid);
			if (sum > m)
				break;
		}

		if (sum > m)
			right = mid - 1;

		else
			left = mid + 1;

		mid = (left + right) / 2;
	}

	return mid;
}

int main()
{
	scanf("%d", &n);
	int large = 0;
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	scanf("%d", &m);
	sort(arr, arr + n);
	printf("%d", bs(arr[n-1]));
}