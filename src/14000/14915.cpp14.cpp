#include <iostream>
#include <string>
using namespace std;

char arr[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
int main()
{
	int m, n;
	string ans, a;
	cin >> m >> n;

	while (m)
	{
		a = ans;
		ans = arr[m%n];
		ans += a;
		m /= n;
	}
	
	if (ans == "")
		ans = "0";
	cout << ans;
}