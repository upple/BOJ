#include <cstdio>
#include <queue>

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
char map[14][8];
int r = 12, c = 6, count;

void drop()
{
	for (int j = 1; j <= c; j++)
	{
		for (int b = r, i = r; i > 0; i--)
		{
			if (map[i][j] != '.')
			{
				map[b][j] = map[i][j];
				if (b != i)
					map[i][j] = '.';
                
				b--;
			}
		}
	}
}
bool bfs()
{
	bool v[13][7] = {}, ret = false;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (map[i][j]!='.' && !v[i][j])
			{
				std::queue<int> Q, g;
				v[i][j] = 1;
				Q.push(i * 20 + j);
				char color = map[i][j];
				while (Q.size())
				{
					g.push(Q.front());
					int x = Q.front() / 20;
					int y = Q.front() % 20;
					Q.pop();
					for (int k = 0; k < 4; k++)
					{
						int nx = x + dx[k], ny = y + dy[k];
						if (map[nx][ny] == color && !v[nx][ny])
						{
							Q.push({ nx * 20 + ny });
							v[nx][ny] = 1;
						}
					}
				}

				if (g.size() >= 4)
				{
					ret = true;
					while (g.size())
					{
						int x = g.front() / 20;
						int y = g.front() % 20;
						g.pop();
						map[x][y] = '.';
					}
				}
			}
		}
	}

	drop();
	return ret;
}
int main()
{
	for (int i = 1; i <= r; i++)
		scanf("%s", map[i] + 1);

	while (bfs())
		count++;

	printf("%d", count);
}