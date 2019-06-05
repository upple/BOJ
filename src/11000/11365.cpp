#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	while (1)
	{
		getline(cin, str);
		if (str == "END")
			return 0;

		cout << string(str.rbegin(), str.rend()) << "\n";
	}
}