#include <iostream>
#define MOD 1000000009
using namespace std;

int dp[1000001] = { 0, 1, 2, 4, };
int solve(int x)
{
	if (x <= 0) return 0;
	if (dp[x]) return dp[x];
	return dp[x] = ((solve(x - 1) + solve(x - 2)) % MOD + solve(x - 3)) % MOD;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		cout << solve(n) << "\n";
	}
}