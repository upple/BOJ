#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	int no_case, sum, score;
	cin >> no_case;
	while (no_case--)
	{
		sum = 0, score = 0;
		cin >> str;
		for (int i = 0; i < str.size(); i++)
		{
			if (str.at(i) == 'O')
				sum += ++score;

			else
				score = 0;
		}

		cout << sum << endl;
	}
	
	return 0;
}