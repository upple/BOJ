#include <iostream>
#include <string>

using namespace std;

int main()
{
	string star="";
	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
		star += '*';

	for (int i = 0; i < num; i++)
	{
		cout << star << endl;
		star.at(i) = ' ';
	}

	return 0;
}
