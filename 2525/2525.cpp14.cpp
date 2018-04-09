#include <iostream>
using namespace std;

int main(void)
{
	int h, m, need;
	scanf("%d %d %d", &h, &m, &need);
	m += h * 60 + need;

	h = m / 60;
	m %= 60;
	if (h >= 24)
		h -= 24;

	printf("%d %d\n", h, m);
	return 0;
}
