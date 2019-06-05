#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	int t;
	string str;
	cin >> t;
	getline(cin, str);
	for (int i = 1; i <= t; i++)
	{
		string str, ans, temp;
		getline(cin, str);
		istringstream strr(str);

		while (strr>>temp)
			ans = temp + " " + ans;

		cout << "Case #" << i << ": " << ans << '\n';
	}
}
