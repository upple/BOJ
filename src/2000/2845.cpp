#include <cstdio>

int main()
{
	int l, p;
	scanf("%d %d", &l, &p);
	
	for (int i = 0; i < 5; i++)
	{
		int x;
		scanf("%d", &x);
		printf("%d ", x - l*p);
	}
}