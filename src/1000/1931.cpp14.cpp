#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, end_time=0, ans=0;
	scanf("%d", &n);
	vector<pair<int, int> > arr(n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr[i].second, &arr[i].first);

	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++)
		if (arr[i].second >= end_time)
			ans++, end_time=arr[i].first;

	printf("%d", ans);
}