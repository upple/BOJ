#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	string str;
	while (1)
	{
		getline(cin, str);
		if (str == "EOI")
			return 0;

		str[0] = tolower(str[0]);
		str[1] = tolower(str[1]);
		str[2] = tolower(str[2]);
		for (int i = 3; i < str.size(); i++)
		{
			str[i] = tolower(str[i]);
			if (str.substr(i - 3, 4) == "nemo")
			{
				cout << "Found\n";
				goto out;
			}
		}

		cout << "Missing\n";
	out:;
	}
}