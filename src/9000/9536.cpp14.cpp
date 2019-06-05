#include <iostream>
#include <sstream>
#include <string>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	string str, tmp;
	cin >> t;

	while (t--)
	{
		set<string> S;
		getline(cin, str);
		getline(cin, str);
		istringstream ipt(str);
		while (1)
		{
			cin >> tmp;
			cin >> tmp;
			if (tmp == "goes")
			{
				cin >> tmp;
				S.insert(tmp);
			}
			else if (tmp == "does")
			{
				while (ipt >> tmp)
				{
					if (S.find(tmp) == S.end())
					{
						cout << tmp << ' ';
					}
				}

				cout << '\n';
				break;
			}
		}
	}
}