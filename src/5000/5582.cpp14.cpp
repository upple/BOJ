#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int dp[4001][4001];
int main()
{
	string a, b;
	int ans = 0;
	cin >> a >> b;
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			if (a[i] == b[j])  ans = max(ans, dp[i + 1][j + 1] = dp[i][j] + 1);
		}
	}

	cout << ans;
}