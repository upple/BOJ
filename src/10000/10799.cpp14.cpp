#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int count = 0, ans=0;
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		char pos = str.at(i);
		if (pos == '(')
		{
			if (str.at(i + 1) == ')')
				ans += count, i++;

			else
				count++;
		}

		else if (str.at(i - 1) == ')')
			count--, ans += 1;
	}

	printf("%d\n", ans);
	return 0;
}
