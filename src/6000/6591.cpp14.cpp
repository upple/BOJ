#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	while (1)
	{
		cin >> a >> b;
		if (a == 0) return 0;
		if (a - b < b) b = a - b;
		long long ans = 1, r = 1;
		while (r<=b)
		{
			ans = ans * (a--) / (r++);
		}

		cout << ans << "\n";
	}
}