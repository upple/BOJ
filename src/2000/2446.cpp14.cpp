#include <iostream>
#include <string>

using namespace std;
int main()
{
	string star;
	int n;

	cin >> n;
	for (int i = 0; i < 2 * n-1; i++)
		star.push_back('*');


	for (int i = 0; i < n-1; i++)
	{
		cout << star << endl;
		star.at(i) = ' ', star.pop_back();
	}

	for (int i = 0; i < n; i++)
	{
		star.at(n - i - 1) = '*';
		cout << star << endl;
		star.push_back('*');
	}

	return 0;
}