#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str = "";
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		str += '*';
		cout << str << endl;
	}
	for (int i = 0; i <n-1; i++)
	{
		str.pop_back();
		cout << str << endl;
	}
}