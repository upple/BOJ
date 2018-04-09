#include <iostream>
#include <string>

using namespace std;
int main()
{
	string star="";
	int n;

	cin >> n;
	for (int i = 0; i < 2*n-1; i++)
			star += "*";

	for (int i = 0; i < n; i++)
	{
		cout << star << endl;
		star.at(i) = ' ';
		star.pop_back();
	}

	return 0;
}