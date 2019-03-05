#include <cstdio>

long long s, c, arr[1000000], min = 1, max = 1111111111, sum = 0;

long long bs()
{
	long long mid=(min+max)/2, sum;
	while (min<=max)
	{
		sum = 0;
		for (int i = 0; i < s; i++)
		{
			sum += arr[i] / mid;
			if (sum >= c)
				break;
		}
		
		if (sum >= c)
			min = mid+1;

		else
			max = mid-1;

		mid = (min + max) / 2;
	}

	return mid;
}
int main()
{
	scanf("%lld %lld", &s, &c);
	for (int i = 0; i < s; i++)
	{
		scanf("%lld", &arr[i]);

		sum += arr[i];
	}

	max = sum / c;

	printf("%lld", sum-bs()*c);
}