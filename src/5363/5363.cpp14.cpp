#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	string str;
	cin >> t;
	getline(cin, str);
	while (t--)
	{
		string s1="", s2="";
		getline(cin, str);

		for (int i=0; i<str.size(); i++)
		{
			if (str[i] == ' ')
			{
				if (s1 == "")
				{
					s1 = str.substr(0, (i == str.size() - 1 ? i : i + 1));
					str.erase(0, (i == str.size() - 1 ? i : i + 1));
					i = -1;
				}

				else
				{
					s2 = str.substr(0, i);
					str.erase(0, (i == str.size() - 1 ? i : i + 1));
					break;
				}
			}
			if (i == str.size() - 1)
				s2 = str, str = "";
		}
		if (str != "")
			str += " ";
		cout << str << s1 << s2 << "\n";
	}
}