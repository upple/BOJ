#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int arr[10000];
int re[10000];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> arr[i];

		sort(arr, arr + n);
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int j = i / 2;
			if (i % 2) re[n - 1 - j] = arr[i];
			else re[j] = arr[i];
		}
		int p = re[n - 1];
		for (int i = 0; i < n; i++)
		{
			ans = max(ans, abs(re[i] - p));
			p = re[i];
		}
		cout << ans << "\n";
	}
}