#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int no_case;
	char temp;
	cin >> no_case;
	while (no_case--)
	{
		vector<char> str;
		string PS, ans="YES";
		cin >> PS;
		for (int i = 0; i < PS.size(); i++)
		{
			char pos = PS.at(i);

			if(pos=='(')
				str.push_back(pos);

			else if (pos == ')')
			{
				if (str.empty() || str.back()==pos)
				{
					ans = "NO";
					break;
				}
					
				str.pop_back();
			}	

		}

		if (!str.empty())
			ans = "NO";

		cout << ans << endl;
	}
	return 0;
}