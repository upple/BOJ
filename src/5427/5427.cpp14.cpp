#include <cstdio>
#include <queue>
using namespace std;

typedef queue< pair<int, int> > myQueue;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int n, m, count;
char map[10001][1000];

void Fbfs(myQueue &Fq)
{
	Fq.push({ -1, -1 });
	while (Fq.size())
	{
		auto cur = Fq.front();
		Fq.pop();
		if (cur.first == -1)
			return;

		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i], ny = cur.second + dy[i];
			if (nx>=0 && nx<n && ny>=0 && ny<m && (map[nx][ny]=='.' || map[nx][ny]=='@'))
				map[nx][ny]='*', Fq.push({ nx, ny });
		}
	}
}

bool Pbfs(myQueue &Pq)
{
	Pq.push({ -1, -1 });
	while (Pq.size())
	{
		auto cur = Pq.front();
		Pq.pop();
		if (cur.first == -1)
		{
			if (Pq.empty())
			{
				printf("IMPOSSIBLE\n");
				return false;
			}

			::count++;
			return true;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i], ny = cur.second + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			{
				printf("%d\n", ::count);
				return false;
			}
			if (map[nx][ny] == '.')
				map[nx][ny] = '@', Pq.push({ nx, ny });
		}
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		::count = 1;
		myQueue Pq, Fq;
		scanf("%d %d", &m, &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%s", map[i]);
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] == '@')
					Pq.push({ i, j });

				else if (map[i][j] == '*')
					Fq.push({ i, j });
			}
		}

		do
		{
			Fbfs(Fq);
		} while (Pbfs(Pq));

	}
}