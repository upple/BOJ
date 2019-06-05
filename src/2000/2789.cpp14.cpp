#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string ans="", mail, test="ABCDEGIMR";
	cin >> mail;
	for (char i : mail)
		if (!binary_search(test.begin(), test.end(), i))
			ans += i;

	cout << ans;
}