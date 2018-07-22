#include <cstdio>

int main()
{
	int n, m, h=0, v=0, num;
	scanf("%d %d", &n, &m);
	
	for(int i=n; i; i--)
	{
		scanf("%d", &num);
		if(h<num)
			h=num;
	}
	for(int i=m; i; i--)
	{
		scanf("%d", &num);
		if(v<num)
			v=num;
	}
	
	printf("%d", h+v);
}