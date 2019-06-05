#include <cstdio>
#include <bitset>
#include <unordered_set>
char map[1001][1001];
int n, m, cnt;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

std::bitset<1000> v[1000];

void solve(int x, int y)
{
	std::unordered_set<int> S;
	
	v[x][y] = 1;
	S.insert(x * 1000 + y);
	while (1)
	{
		int d;
		switch (map[x][y])
		{
		case 'N': d = 3; break;
		case 'S': d = 2; break;
		case 'W': d = 1; break;
		case 'E': d = 0;
		}

		x += dx[d], y += dy[d];

		if (S.find(x*1000+y)!=S.end())
			return;

		if (v[x][y])
		{
			cnt--;
			return;
		}
		
		v[x][y] = 1;
		S.insert(x * 1000 + y);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", map[i]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!v[i][j])
				cnt++, solve(i, j);

	printf("%d", cnt);
}