#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > map;
vector<int> res;
int n, m, h, ans = 0;

bool solve(int x, int y, int c, vector<int> res)
{
	for (int i = x; i <= h; i++)
	{
		for (int j = y; j < n; j++)
		{
			if (map[i][j])
				swap(res[j], res[j + 1]);

			else if (c && !map[i][j - 1] && !map[i][j + 1])
			{
				map[i][j] = 1;
				swap(res[j], res[j + 1]);
				if (solve(i, j + 1, c - 1, res))
					return true;

				map[i][j] = 0;
				swap(res[j], res[j + 1]);
			}

		}
		y = 1;
	}

	for (int i = 1; i <= n; i++)
		if (res[i] != i)
			return false;

	return true;
}
int main()
{
	scanf("%d %d %d", &n, &m, &h);
	map.assign(h + 1, vector<int>(n + 2, 0));
	res.assign(n + 1, 0);
	for (int i = 1; i <= n; i++)
		res[i] = i;
        
	while (m--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		map[a][b] = 1;
	}


	for (int i = 0; i <= 3; i++)
	{
		if (solve(1, 1, i, res))
		{
			printf("%d", i);
			return 0;
		}
	}

	printf("-1");
}