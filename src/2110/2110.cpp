#include <iostream>
#include <algorithm>
using namespace std;
int arr[200001];
int n, c, ans;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> c;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
	arr[n] = 0x7fffffff;
	int l = 1, r = arr[n - 1];
	int mid = (l + r) / 2, prev, v;
	while (l <= r)
	{
		prev = 0, v = c;
		while (--v)
		{
			int cur = prev;
			while (arr[++cur] < arr[prev] + mid);
			if (cur == n) break;
			prev = cur;
		}
		if (!v)
		{
			ans = max(ans, mid);
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
		mid = (l + r) / 2;

	}
	cout << ans;
}