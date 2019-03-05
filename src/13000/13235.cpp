#include <cstdio>
#include <cstring>
int main()
{
	char str[21];

	scanf("%s", str);
	int size = strlen(str);
	for (int i = 0; i < size / 2; i++)
	{
		if (str[i] != str[size - i - 1])
		{
			printf("false");
			return 0;
		}
	}
	printf("true");
}