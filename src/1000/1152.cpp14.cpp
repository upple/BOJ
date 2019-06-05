#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	int count=0;

	getline(cin, str);

	for (int i = 0; i < str.size(); i++)
		if (str.at(i) != ' ')
		{
			count++;
			int j = i;
			for (; j!=str.size() && str.at(j) != ' '; j++);

			i = j - 1;
		}

	cout << count << endl;
	return 0;
}