#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int ans = 0;

	for (int q = 0; q < m; q++)
	{
		int l = 1, r = n / k;
		while (l <= r)
		{
			int mid = l + r >> 1;
			int cnt = 0;
			int cur = arr[q];
			for (int i = 1; i < m; i++)
			{
				if (arr[(i + q) % m] - cur >= mid)
				{
					cnt++;
					cur = arr[(i + q) % m];
				}
			}

			if (arr[q] + n - cur >= mid) cnt++;
			if (cnt >= k)
			{
				l = mid + 1;
				ans = max(ans, mid);
			}

			else r = mid - 1;
		}
	}


	cout << ans;
}