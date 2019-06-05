#include <iostream>
#include <string>
using namespace std;
int main()
{
	string j, d;
	cin >> j >> d;
	if (j.size() >= d.size())
		cout << "go" << endl;

	else
		cout << "no" << endl;

	return 0;
}	