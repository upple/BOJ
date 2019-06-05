#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	char str[101];
	scanf("%s", str);
	for (int i = 0; str[i]; i++)
	{
		if (isupper(str[i]))
			printf("%c", str[i]);
	}

	return 0;
}
