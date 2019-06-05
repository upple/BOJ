#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n;
	string star="";
	cin >> n;
	for (int i = 0; i < n; i++)
		star += ' ';

	for (int i = 0; i < n; i++)
	{
		star[n - 1 - i] = '*';
		cout << star << endl;
	}
	for (int i = 0; i < n - 1; i++)
	{
		star[i] = ' ';
		cout << star << endl;
	}

	return 0;
}