#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		map<string, int> M;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string a, b;
			cin >> a >> b;
			M[b]++;
		}

		long long ans = 1;
		for (auto &i : M)
		{
			ans *= i.second + 1;
		}

		cout << ans - 1 << "\n";
	}
}