#include <iostream>
#include <vector>
using namespace std;

int n;
bool chk[101];
vector<long long> arr, ans;

bool solve(int p, long long x)
{
	if (p == n) return true;
	for (int i = 0; i < n; i++)
	{
		if (chk[i] == true) continue;

		chk[i] = true;
		if (p == 0 || (x % 3 == 0 && x / 3 == arr[i]))
		{
			if (solve(p + 1, arr[i]) == true)
			{
				ans.push_back(arr[i]);
				return true;
			}
		}
		else if (p == 0 || (arr[i] % 2 == 0 && x == arr[i] / 2))
		{
			if (solve(p + 1, arr[i]) == true)
			{
				ans.push_back(arr[i]);
					return true;
			}
		}
		chk[i] = false;
	}
	return false;
}
int main()
{
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	solve(0, 0);
	for (int i = n - 1; i >= 0; i--)
		cout << ans[i] << ' ';
}