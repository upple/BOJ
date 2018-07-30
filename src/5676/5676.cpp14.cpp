#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define MAX 100001
using namespace std;

vector<int> pt, z, arr;
int n, k;

void update(int p, int x)
{
	int tp = p;
	if(x) x = x / abs(x);
	if (arr[p] == x) return;

	if (x)
	{
		if (arr[p])
		{
			while (tp <= n)
			{
				pt[tp] = -pt[tp];
				tp += (tp & -tp);
			}
		}
		else
		{
			while (tp <= n)
			{
				z[tp]--;
				pt[tp] *= x;
				tp += (tp & -tp);
			}
		}
	}
	else
	{
		while (tp <= n)
		{
			z[tp]++;
			tp += (tp & -tp);
		}
	}

	arr[p] = x;
}

int query(int l, int r)
{
	int ln = 1, lz = 0, rn = 1, rz = 0;
	while (r)
	{
		rn *= pt[r];
		rz += z[r];
		r -= (r&-r);
	}
	while (l)
	{
		ln *= pt[l];
		lz += z[l];
		l -= (l&-l);
	}

	if (rz - lz > 0) return 0;

	return rn * ln;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	while (cin >> n >> k)
	{
		pt.resize(n + 1, 1), z.resize(n + 1), arr.resize(n + 1, 1);
		for (int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			update(i, x);
		}

		while (k--)
		{
			char cmd;
			int i, v;
			cin >> cmd >> i >> v;
			if (cmd == 'C')
				update(i, v);

			else
			{
				switch (query(i - 1, v))
				{
				case -1:
					cout << "-"; break;
				case 0:
					cout << 0; break;
				case 1:
					cout << "+"; break;
				}
			}
		}

		cout << "\n";
		pt.clear(), z.clear(), arr.clear();
	}
}