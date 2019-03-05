#include<iostream>
#include<string>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int p;
		string str;
		cin >> p >> str;
		str.erase(str.begin() + p - 1);
		cout << str << endl;
	}
}