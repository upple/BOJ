#include <cstdio>

long long k, n, arr[10000], min = 1, max, sum = 0;

long long bs()
{
	long long mid=(min+max)/2, sum;
	while (min<=max)
	{
		sum = 0;
		for (int i = 0; i < k; i++)
		{
			sum += arr[i] / mid;
			if (sum >= n)
				break;
		}
		
		if (sum >= n)
			min = mid+1;

		else
			max = mid-1;

		mid = (min + max) / 2;
	}

	return mid;
}
int main()
{
	scanf("%lld %lld", &k, &n);
	for (int i = 0; i < k; i++)
	{
		scanf("%lld", &arr[i]);
		sum += arr[i];
	}

	max = sum / n;

	printf("%lld", bs());
}