#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, ans=0;
	scanf("%d", &n);

	vector<pair<int, int> > arr(n), room;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}

	sort(arr.begin(), arr.end());
	for (auto &i : arr)
	{
		int cl = i.first, cr = i.second;
		bool chk = 0;
		for (auto &j : room)
		{
			int &l = j.first, &r = j.second;
			if (cl >= r)
			{
				l = cl, r = cr;
				chk = 1;
				break;
			}

		}
		if (!chk)
			room.push_back({ cl, cr }), ans++;

	}

	printf("%d", ans);
}