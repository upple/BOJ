#include <cstdio>
#include <algorithm>
int main()
{
	long long a, b;
	scanf("%lld %lld", &a, &b);
	
	if(a>b)
		std::swap(a, b);
		
	long long m=b-a, p=a+b;
	printf("%lld", p*((m+1)/2)+(!(p%2))*p/2);
}