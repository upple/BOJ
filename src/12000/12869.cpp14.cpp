#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int w[] = { 9, 3, 1 };
int dp[61][61][61];
int c;
int solve(vector<int> &arr)
{
	if (arr.empty()) return c;
	int d[3] = {};
	for (int i = 0; i < arr.size(); i++)
	{
		d[i] = arr[i];
	}

	if (dp[d[0]][d[1]][d[2]]) return dp[d[0]][d[1]][d[2]];
	c++;
	sort(arr.begin(), arr.end());
	int res = 100;
	do
	{
		vector<int> tmp;
		for (int i = 0; i < arr.size(); i++)
		{
			int x = arr[i] - w[i];
			if (x <= 0) continue;
			tmp.push_back(x);
		}

		res = min(res, solve(tmp));
	} while (next_permutation(arr.begin(), arr.end()));
	c--;
	return dp[d[0]][d[1]][d[2]] = res;
}
int main()
{
	int n;
	vector<int> arr;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		arr.push_back(x);
	}

	cout << solve(arr);
}