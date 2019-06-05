#include <iostream>
#include <algorithm>
using namespace std;
pair<int, int> arr[100001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr + 1, arr + n + 1);

	while (m--)
	{
		int i, j, k;
		cin >> i >> j >> k;

		for (int x = 1; x <= n; x++)
		{
			if (arr[x].second >= i && arr[x].second <= j)
			{
				k--;
				if (k == 0)
				{
					cout << arr[x].first << "\n";
					break;
				}
			}
		}
	}
}