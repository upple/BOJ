#include <cstdio>
#include <cctype>
using namespace std;

int main()
{
	char str[101];
	scanf("%s", str);
	for(int i=0; str[i]; i++)
	{
		if(islower(str[i]))
			printf("%c", toupper(str[i]));

		else
			printf("%c", tolower(str[i]));

	}

}
