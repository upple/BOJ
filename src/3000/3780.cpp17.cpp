#include <iostream>
#include <algorithm>
#define MOD 1000
using namespace std;
int p[20001], c[20001];

int Find(int x)
{
	if (x == p[x]) return x;
	int px = Find(p[x]);
	c[x] += c[p[x]];
	return p[x] = px;
}

void Union(int a, int b)
{
	c[a] = abs(a - b) % MOD;
	p[a] = b;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			p[i] = i, c[i] = 0;

		char cmd;
		int a, b;
		while (1)
		{
			cin >> cmd;
			if (cmd == 'O') break;
			if (cmd == 'E')
			{
				cin >> a;
				Find(a);
				cout << c[a] << "\n";
			}
			else
			{
				cin >> a >> b;
				Union(a, b);
			}
		}

	}
}