#include <cstdio>
#include <cmath>

int main()
{
	int k, count=0, div=2, ans=0;
	scanf("%d", &k);

	while(k!=1)
	{
		while(!(k%div))
		{
			count++;
			k/=div;
		}
		div++;
	}

	while((int)pow(2, ans)<count)
		ans++;
	printf("%d", ans);
}
