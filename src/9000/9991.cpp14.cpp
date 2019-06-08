#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<string, int> > arr;
int main()
{
	int w, n;
	cin >> w >> n;
	arr.resize(w + 1);
	for (int i = 1; i <= w; i++)
		cin >> arr[i].first, arr[i].second = i;

	sort(arr.begin(), arr.end());

	while (n--)
	{
		int k;
		string sub;
		cin >> k >> sub;
		auto it = lower_bound(arr.begin(), arr.end(), pair<string, int>({sub, 0}));
		it += k - 1;
		if (it >= arr.end())
		{
			cout << "-1\n";
			continue;
		}

		if (it->first.substr(0, sub.size()) != sub)
			cout << "-1\n";

		else
			cout << it->second << "\n";
	}
}