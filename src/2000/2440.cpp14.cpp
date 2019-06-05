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

	while (num--)
	{
		cout << star << endl;
		star.pop_back();
	}

	return 0;
}
