#include <cstdio>
#include <cctype>

char arr[6][16] = {};
int main()
{
	int n = 0;
	while (scanf("%s", arr[n++]) != EOF);

	for (int j = 0; j < 15; j++)
		for (int i = 0; i < 5; i++)
			if (isalnum(arr[i][j]))
				putchar(arr[i][j]);
}