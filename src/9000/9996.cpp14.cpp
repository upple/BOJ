#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, star;
	string pattern, pattern_f, pattern_e, str;

	cin >> n >> pattern;
	for (int i = 0; i < pattern.size(); i++)
	{
		if (pattern[i] == '*')
		{
			star = i;
			break;
		}
	}

	pattern_f = pattern.substr(0, star);
	pattern_e = pattern.substr(star + 1, str.size() - star - 1);

	for (int i = 0; i < n; i++)
	{
		cin >> str;

		if (str.size()>=pattern.size()-1 && str.substr(0, star) == pattern_f && str.substr(str.size() - pattern_e.size(), pattern_e.size()) == pattern_e)
			cout << "DA\n";

		else
			cout << "NE\n";

	}
}