#include <cstdio>

int main()
{
	int num, ans = 0;
	while (~scanf("%d", &num)) 
	{
		if (num > 0)
			ans++;
	}
	printf("%d", ans);
}