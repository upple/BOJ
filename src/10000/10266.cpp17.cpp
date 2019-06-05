#include <iostream>
#include <algorithm>
#define MAX 360000
using namespace std;

typedef unsigned long long ull;
ull p[MAX];
ull a, b;
int reala[MAX], realb[MAX];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, x;
	cin >> n;
	p[0] = 1;
	for (int i = 1; i < MAX; i++)
		p[i] = p[i - 1] * 7;

	for (int i = n; i--;)
	{
		cin >> x;
		a += p[MAX - x - 1];
		reala[x]++;
	}

	for (int i = n; i--;)
	{
		cin >> x;
		b += p[MAX - x - 1];
		realb[x]++;
	}

	for (int i = 0; i < MAX; i++)
	{
		if (a == b)
		{
			bool chk = true;
			for (int j = 0; j < MAX; j++)
			{
				if (reala[j] != realb[(j + i) % MAX])
				{
					chk = false;
					break;
				}

			}
			
			if (chk == true)
			{
				cout << "possible";
				return 0;
			}
		}

		b -= realb[i] * p[MAX - 1];
		b = b * 7 + realb[i];
	}

	cout << "impossible";
}