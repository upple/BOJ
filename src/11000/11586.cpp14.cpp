#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int n, k;
	cin >> n;

	string *str = new string[n];
	for (int i = 0; i < n; i++)
		cin >> str[i];

	cin >> k;
	if (k == 1)
		for (int i = 0; i < n; i++)
			cout << str[i] << endl;

	else if (k == 2)
		for (int i = 0; i < n; i++)
		{
			reverse(str[i].begin(), str[i].end());
			cout << str[i] << endl;
		}

	else
		for (int i = n - 1; i >= 0; i--)
			cout << str[i] << endl;
}