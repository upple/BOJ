#include <cstdio>

int main()
{
	int n;
	long long arr[100000], ans=0;
	scanf("%d %lld", &n, &arr[0]);
	for(int i=1; i<n; i++)
	{
		scanf("%lld", &arr[i]);
		ans+=arr[i]*arr[i-1];
		arr[i]+=arr[i-1];
	}

	printf("%lld", ans);
}
