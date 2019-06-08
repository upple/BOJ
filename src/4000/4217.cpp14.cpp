#include <cstdio>
#include <bitset>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
struct xy { int x, y; };
char Sign[] = "WAKJSD";
vector<vector<bool> > map, v;
int h, w;

void bfs_z(int x, int y)
{
	queue<xy> Q;
	Q.push({ x, y });
	v[x][y] = 1;
	while (Q.size())
	{
		x = Q.front().x, y = Q.front().y;
		Q.pop();
		int i = 4;
		while (i--)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && nx < h + 2 && ny >= 0 && ny < w + 2 && map[nx][ny] == 0 && !v[nx][ny])
			{
				v[nx][ny] = 1;
				Q.push({ nx, ny });
			}
		}
	}
}

char bfs_o(int x, int y)
{
	int cnt = 0;
	queue<xy> Q;
	Q.push({ x, y });
	v[x][y] = 1;
	while (Q.size())
	{
		x = Q.front().x, y = Q.front().y;
		Q.pop();
		int i = 4;
		while (i--)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && nx < h + 2 && ny >= 0 && ny < w + 2 && !v[nx][ny])
			{
				if (map[nx][ny])
				{
					v[nx][ny] = 1;
					Q.push({ nx, ny });
				}
				else
				{
					cnt++;
					bfs_z(nx, ny);
				}
			}
		}
	}

	return Sign[cnt];
}
int main()
{
	int tc = 0;
	while (++tc)
	{
		vector<char> ans;
		scanf("%d %d", &h, &w);
		if (h == 0) return 0;
		w *= 4;
		map.clear(), v.clear();
		map.assign(h + 2, vector<bool>(w + 2));
		v.assign(h + 2, vector<bool>(w + 2));
		int num;
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w;)
			{
				scanf("%1x", &num);
				int div = 8;
				while (div)
				{
					map[i][j] = num / div;
					num %= div;
					div >>= 1;
					j++;
				}
			}
		}

		bfs_z(0, 0);
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
				if (map[i][j] && !v[i][j])
					ans.push_back(bfs_o(i, j));

		sort(ans.begin(), ans.end());
		printf("Case %d: ", tc);
		for (char i : ans)
			printf("%c", i);

		printf("\n");
	}
}