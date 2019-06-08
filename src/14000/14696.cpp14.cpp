#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int t, n, num;
	scanf("%d", &t);
	while (t--)
	{
		pair<pair<int, int>, pair<int, int> > a[2];
		for (int i = 0; i < 2; i++)
		{
			scanf("%d", &n);
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &num);
				switch (num)
				{
				case 1: a[i].second.second++; break;
				case 2: a[i].second.first++; break;
				case 3:	a[i].first.second++; break;
				case 4: a[i].first.first++; break;
				}
			}

		}

		if (a[0] == a[1])
			printf("D\n");

		else
			printf("%c\n", a[0] > a[1] ? 'A' : 'B');
	}
}