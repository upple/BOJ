#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, count=0;
		scanf("%d", &n);
		vector<pair<int, int> >L(n);

		for (int i = 0; i < n; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			L[i]={ a, -b };
		}
		sort(L.begin(), L.end());
		int x = L.begin()->first, y = L.begin()->second;
		for (auto i : L)
		{
			if (i.first == x || i.second >= y)
			{
				count++;
				if (i.first > x)
					x = i.first;

				if (i.second > y)
					y = i.second;
			}
		}
		printf("%d\n", count);
	}
	
}
