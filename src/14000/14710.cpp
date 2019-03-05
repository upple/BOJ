#include <cstdio>

int main()
{
	int h, m;
	scanf("%d %d", &h, &m);
	printf("%c", (h % 30 * 12 == m ? 'O' : 'X'));
}