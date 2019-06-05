#include <iostream>
#define MOD 1000000009
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int ans = 0;
		for (int i = n; i >= 0; i -= 3)
			for (int j = i; j >= 0; j -= 2)
				ans++;

		cout << ans << "\n";
	}
}