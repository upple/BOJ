#include <cstdio>
#pragma GCC optimize("O3")
int main()
{
	float a, b, c;
	scanf("%f %f %f", &a, &b, &c);
	if(a+b==c) printf("%.f+%.f=%.f", a, b, c);
	else if(a-b==c) printf("%.f-%.f=%.f", a, b, c);
	else if(a*b==c) printf("%.f*%.f=%.f", a, b, c);
	else if(b!=0 && a/b==c) printf("%.f/%.f=%.f", a, b, c);
	else if(a==b+c) printf("%.f=%.f+%.f", a, b, c);
	else if(a==b-c) printf("%.f=%.f-%.f", a, b, c);
	else if(a==b*c) printf("%.f=%.f*%.f", a, b, c);
	else if(c!=0 && a==b/c) printf("%.f=%.f/%.f", a, b, c);
}