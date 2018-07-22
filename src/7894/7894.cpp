#include<cstdio>
#include<cmath>
int main()
{
	int t;
	double m;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%lf", &m);
		double ans = 0;
		do
			ans += log10(m);
		while (--m);
		printf("%d\n", (int)ans+1);
	}

}