#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	const int Prime[25] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
	int no_case;
	int num, count = 0;

	scanf("%d", &no_case);
	while (no_case--)
	{
		scanf("%d", &num);
		if (binary_search(Prime, Prime + 25, num))
			count++;
	}

	printf("%d\n", count);
	return 0;
}
