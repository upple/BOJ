#include <cstdio>
#include <algorithm>
using namespace std;

long long arr[100001];
int main()
{
	int n;
	long long m, ans = 2000000001;
	scanf("%d %lld", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);
    
	arr[n] = ans;

	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		long long tmp = m + arr[i];
		tmp = *lower_bound(arr, arr + n, tmp) - arr[i];
		ans = min(ans, tmp);

	}

	printf("%lld", ans);
}