#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(void)
{
	while (1)
	{
		int lower = 0, upper = 0, number = 0, space = 0;
		string str;
		getline(cin, str, '\n');
		if (str=="")
			break;

		for (int i = 0; i < str.size(); i++)
		{
			int x = str.at(i);
			if (x >= 97 && x <= 122)
				lower++;

			else if (x >= 65 && x <= 900)
				upper++;

			else if (x >= 48 && x <= 57)
				number++;

			else if (x == 32)
				space++;

		}

		cout << lower << " " << upper << " " << number << " " << space << endl;
	}

	return 0;
}
