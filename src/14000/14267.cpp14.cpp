#include <iostream>
using namespace std;

int su[100001], dp[100001];
bool v[100001];

int get(int x)
{
	if (v[x])
		return dp[x];

	if (x == 1)
	{
		v[x] = 1;
		return dp[x];
	}

	dp[x] += get(su[x]);
	v[x] = 1;
	return dp[x];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> su[i];

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		dp[a] += b;
	}

	for (int i = 1; i <= n; i++)
		cout << get(i) << " ";
}