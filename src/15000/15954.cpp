#include <cstdio>
#include <cmath>
#include <algorithm>
long double arr[501], sum[501];
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++)
	{
		scanf("%Lf", &arr[i]);
		sum[i] = sum[i - 1] + arr[i];
	}

	long double ans = 9999999999999;
	for (int q = k; q <= n; q++)
	{
		for (int i = q; i <= n; i++)
		{
			long double avg = (sum[i] - sum[i - q]) / q;
			long double cand = 0;
			for (int j = i - q + 1; j <= i; j++)
			{
				cand += (arr[j] - avg)*(arr[j] - avg);
			}
			cand = sqrtl(cand / q);
			ans = std::min(ans, cand);
		}
	}

	printf("%.12Lf", ans);
}