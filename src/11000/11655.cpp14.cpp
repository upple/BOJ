#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;

int main(void)
{
	char str;

	while (scanf("%c", &str) != EOF)
	{
		if (islower(str))
			str = ((str - 'a') + 13) % 26 + 'a';

		else if (isupper(str))
			str = ((str - 'A') + 13) % 26 + 'A';

		printf("%c", str);
	}

	return 0;
}
