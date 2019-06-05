#include <cstdio>

int main()
{
	int n, k, sum=0;
	scanf("%d %d", &n, &k);
	
	for(int i=k; i; i--)
	{
		int num;
		scanf("%d", &num);
		sum+=(num+1)/2;
	}
	
	printf("%s", sum>=n?"YES":"NO");
}