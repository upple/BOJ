#include<cstdio>

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d", (b-a>c-b?b-a-1:c-b-1));
}
