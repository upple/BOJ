#include <iostream>
#include <algorithm>
using namespace std;
int arr[100000];

int center(int l, int r)
{
	int mid = (l + r) / 2;
	int res = arr[mid], cur = arr[mid];
	int ll = mid - 1, rr = mid + 1;
	while (ll >= l || rr <= r)
	{
		if ((rr > r) || (ll >= l) && (arr[ll] > arr[rr]))
		{
			cur = min(cur, arr[ll]);
			res = max(res, (rr - ll)*cur);
			ll--;
		}
		else
		{
			cur = min(cur, arr[rr]);
			res = max(res, (rr - ll)*cur);
			rr++;
		}
	}

	return res;
}
int solve(int l, int r)
{
	int mid = (l + r) / 2;
	if (l == r)
		return arr[l];

	return max(max(solve(l, mid), solve(mid + 1, r)), center(l, r));
}
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin>>arr[i];

	cout << solve(0, n - 1);
}