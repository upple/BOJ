#include<stdio.h>
int main()
{
	long long n, b, c, *arr, ans=0;
	scanf("%lld", &n);
	arr=new long long[n];
	for(int i=0; i<n; i++)
		scanf("%lld", &arr[i]);

	scanf("%lld %lld", &b, &c);
	for(int i=0; i<n; i++)
	{
		if(b<=arr[i])
			ans+=(arr[i]-b)/c+((arr[i]-b)%c>0);

		ans++;
	}

	printf("%lld", ans);
	delete []arr;
}
