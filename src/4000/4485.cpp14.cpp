#include <cstdio>
#include <vector>
#include <queue>
#define INF 124124142
using namespace std;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int map[125][125];
int n;
int main()
{
	int test_case = 0;
	while (++test_case)
	{
		scanf("%d", &n);
		if (!n)
			return 0;

		priority_queue<pair<int, pair<int, int> > > pq;
		vector<vector<int> > dist(n, vector<int>(n, INF));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &map[i][j]);

		dist[0][0] = map[0][0];
		pq.push({ -dist[0][0], { 0, 0 } });
		while (!pq.empty())
		{
			int cost = -pq.top().first, x = pq.top().second.first, y = pq.top().second.second;
			pq.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i], ny = y + dy[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny<n && dist[nx][ny]>cost + map[nx][ny])
					dist[nx][ny] = cost + map[nx][ny], pq.push({ -dist[nx][ny], {nx, ny} });
			}

		}
		printf("Problem %d: %d\n", test_case, dist[n - 1][n - 1]);
	}
}