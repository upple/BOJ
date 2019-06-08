#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int y1, y2, y3, y4;
	for (int i = 0; i < 3; i++)
	{
		scanf("%d %d %d %d", &y1, &y2, &y3, &y4);
		switch (y1 + y2 + y3 + y4)
		{
		case 0:
			printf("D"); break;
		case 1:
			printf("C"); break;
		case 2:
			printf("B"); break;
		case 3:
			printf("A"); break;
		case 4:
			printf("E"); break;

		}
		printf("\n");
	}
	return 0;
}
