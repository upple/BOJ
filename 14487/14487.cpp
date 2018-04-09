#include <cstdio>

int main()
{
	int max=0, sum=0, cost, n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &cost);
		sum+=cost;
		if(max<cost)
			max=cost;
	}
	printf("%d", sum-max);

}
