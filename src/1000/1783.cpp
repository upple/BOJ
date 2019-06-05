#include <cstdio>

int main()
{
	int n, m, ans;
	scanf("%d %d", &m, &n);

	if(m>=3)
	{
		if(n>=7)
			ans=n-2;

		else if(n>=5)
			ans=4;

		else
			ans=n;
	}

	else
	{
		if(m==2)
			ans=(n-1)/2+1<4?(n-1)/2+1:4;

		else
			ans=1;
	}

	printf("%d", ans);
}
