#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, arr[1000001], p[1000001] = {};
	vector<int> ans;
	scanf("%d %d", &n, &arr[0]);
	ans.push_back(arr[0]);

	for (int i = 1; i < n; i++)
	{
		scanf("%d", &arr[i]);
		if (ans.back() < arr[i])
			p[i] = ans.size(), ans.push_back(arr[i]);

		else
		{
			auto it = lower_bound(ans.begin(), ans.end(), arr[i]);
			*it = arr[i];
			p[i] = it - ans.begin();
		}
	}

	for (int i = n - 1, k=ans.size()-1; i >= 0; i--)
	{
		if (p[i] == k)
			ans[k] = arr[i], k--;
	}

	printf("%d\n", ans.size());
	for (auto i : ans)
		printf("%d ", i);
}