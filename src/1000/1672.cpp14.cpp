#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<string, char> M;
	M["AA"] = 'A', M["AG"] = 'C', M["AC"] = 'A', M["AT"] = 'G';
	M["GA"] = 'C', M["GG"] = 'G', M["GC"] = 'T', M["GT"] = 'A';
	M["CA"] = 'A', M["CG"] = 'T', M["CC"] = 'C', M["CT"] = 'G';
	M["TA"] = 'G', M["TG"] = 'A', M["TC"] = 'G', M["TT"] = 'T';
	int n;
	string str;

	cin >> n >> str;
	while (str.size() != 1)
	{
		char ch = M[str.substr(str.size() - 2, 2)];
		str.pop_back();
		str.back()=ch;
	}
	cout << str;
}