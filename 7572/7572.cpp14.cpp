#include<cstdio>

int main()
{
	int year;
	scanf("%d", &year);

	printf("%c%d", ((year + 8) % 12) + 65, (year + 6) % 10);
}