#include <iostream>
#include <string>

using namespace std;
int main()
{
	string star;
	int n;

	cin >> n;
	for (int i = 0; i < 2 * n; i++)
		star.push_back(' ');


	for (int i = 0; i < n; i++)
	{
		star.at(i) = '*', star.at(2*n - i - 1) = '*';
		cout << star << endl;
	}
	for (int i = 0; i < n; i++)
	{
		star.at(n-i-1) = ' ', star.at(n+i)= ' ';
		cout << star << endl;
	}

	return 0;
}