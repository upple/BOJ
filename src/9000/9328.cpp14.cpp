#include <cstdio>
#include <queue>
#include <algorithm>
#include <cctype>
using namespace std;

struct xy
{
	int x, y;
};

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		queue<xy> sQ, mQ;
		int h, w, curKey=0, nextKey=0, ans=0;
		int visit[100][100] = {};
		char map[100][101], key[27];

		scanf("%d %d", &h, &w);
		for (int i = 0; i < h; i++)
		{
			scanf("%s", map[i]);
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] != '*' && (i == 0 || j == 0 || i == h - 1 || j == w - 1))
				{
					sQ.push({ i, j });
					visit[i][j] = 1;
				}
			}
		}

		scanf("%s", key);

		if (key[0] == '0')
			key[0] = 0;

		for (int i = 0; key[i]; i++)
		{
			nextKey += (1 << (key[i] - 'a'));
		}

		while (sQ.size())
		{
			std::swap(mQ, sQ);
			curKey = nextKey;
			while (mQ.size())
			{
				int x = mQ.front().x, y = mQ.front().y;
				mQ.pop();

				char &ch = map[x][y];

				if (ch == '$')
				{
					ans++;
				}

				else if (islower(ch) && (nextKey & (1 << (ch - 'a'))) == 0)
				{
					nextKey += (1 << (ch - 'a'));
				}

				else if (isupper(ch) && (curKey & (1 << (ch - 'A'))) == 0)
				{
					sQ.push({ x, y });
					continue;
				}

				for (int i = 0; i < 4; i++)
				{
					int nx = x + dx[i], ny = y + dy[i];
					if (nx >= 0 && nx < h && ny >= 0 && ny < w && map[nx][ny] != '*' && !visit[nx][ny])
					{
						mQ.push({ nx, ny });
						visit[nx][ny] = 1;
					}
				}
			}
			if (curKey == nextKey)
				goto out;
		}

	out:;
		printf("%d\n", ans);
	}

}