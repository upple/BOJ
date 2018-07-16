#include <iostream>
using namespace std;

int su[100001], dp[100001], stress[100001];
int v[100001], cnt;
int get(int x, int c)
{
	if (v[x]==c)
		return dp[x];

	if (x == 1)
	{
		v[x] = c;
		return dp[x];
	}

	dp[x] = stress[x] + get(su[x], c);
	v[x] = c;
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
		int a, b, c;
		cin >> a >> b;
		if (a == 2)
		{
			cout << get(b, ++cnt) << "\n";
		}
		else
		{
			cin >> c;
			stress[b] += c;
		}
	}

}