#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int no_case;
	cin >> no_case;
	while(no_case--)
	{
		string str1, str2;
		cin >> str1 >> str2;
		cout << "Distances:";
		for (int i = 0; i < str1.size(); i++)
		{
			int a = str1.at(i), b = str2.at(i);
			if (a > b)
				b += 26;
			cout << " " << b-a;
		}

		cout << endl;
	}

	return 0;
}