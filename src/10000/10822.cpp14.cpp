#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	int pos=0, ans=0;

	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		if (i == str.size() - 1 || str[i + 1] == ',')
			ans += stoi(str.substr(pos, i + 1)), pos = i + 2;
	}

	cout << ans << endl;

}