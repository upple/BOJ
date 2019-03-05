#include <iostream>
#include <string>

using namespace std;
int main()
{
	string star="";
	int n;

	cin >> n;
	for (int i = 0; i < n-1; i++)
			star += " ";

	for (int i = 0; i < n; i++)
	{
		star += '*';
		star.at(n - i - 1) = '*';
		cout << star << endl;
	}

	return 0;
}