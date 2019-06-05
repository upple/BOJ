#include <cstdio>
 
int main()
{
	long long ans=0, n;
	scanf("%lld", &n);
 
	for(long long i=1; i<n; i++)
		ans+=i*n+i;
 
	printf("%lld", ans);
}