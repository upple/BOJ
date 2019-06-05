#include <cstdio>

int arr[1000000];
int main()
{
	long long n, num, sum=0, ans=0;
	scanf("%lld", &n);
	
	for(int i=0; i<n; i++)
	{
		scanf("%lld", &arr[i]);
		sum+=arr[i];
	}
	
	for(int i=0; i<n; i++)
	{
		sum-=arr[i];
		ans+=sum*arr[i];
	}
	
	printf("%lld", ans);
}
