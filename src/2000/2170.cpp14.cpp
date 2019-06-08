#include <cstdio>
#include <algorithm>
using namespace std;

pair<int, int> arr[1000000];
int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		if (a > b)
			swap(a, b);
		arr[i] = { a, b };
	}

	sort(arr, arr + n);

	int l = arr[0].first, r = arr[0].second;
	int ans = 0;
	for(int i=1; i<n; i++)
	{
		int cl = arr[i].first, cr = arr[i].second;
		if (cl <= r)
			r = max(r, cr);

		else
		{
			ans += r - l;
			l = cl, r = cr;
		}
	}

	ans += r - l;
	printf("%d", ans);
}