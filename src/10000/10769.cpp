#include <cstdio>

int main()
{
	int cur = 0, happy = 0, sad = 0;
	char ch;
	while (scanf("%c", &ch) != EOF)
	{
		switch (cur)
		{
		case 0:
			if (ch == ':')
				cur = 1;

			break;
		case 1:
			if (ch == '-')
				cur = 2;
			else
				cur = 0;

			break;
		case 2:
			if (ch == ')')
				happy++;

			else if (ch == '(')
				sad++;

			cur = 0;
			break;

		}
	}

	if (happy > sad)
		printf("happy");

	else if (sad > happy)
		printf("sad");

	else if (!happy && !sad)
		printf("none");

	else
		printf("unsure");
}