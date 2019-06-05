#include<cstdio>
#include<queue>
#define INF 1235702702791
using namespace std;

long long adj[500][500];
long long dist[500];
int n;

void initAdj()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			adj[i][j] = INF;

		adj[i][i] = 0;
		dist[i] = INF;
	}
}

void djstra(int s)
{
	int pos = s, minpos = 0;
	long long min;
	bool visit[500] = {};

	for (int i = 0; i < n; i++)
		dist[i] = INF;

	dist[pos] = 0;
	visit[pos] = true;
	for (int i = 0; i < n; i++)
	{
		min = INF;
		for (int j = 0; j < n; j++)
		{
			if (dist[j] > dist[pos] + adj[pos][j])
			{
				dist[j] = dist[pos] + adj[pos][j];
			}

			if (dist[j] < min && !visit[j])
				min = dist[j], minpos = j;
		}

		if (min == INF)
			break;
		pos = minpos;
		visit[minpos] = true;
	}

}

void deleteRoot(int dest, long long min)
{
	queue<int>Q;
	Q.push(dest);

	while (!Q.empty())
	{
		int pos = Q.front();
		Q.pop();
		for (int i = 0; i < n; i++)
			if (dist[pos] == dist[i] + adj[i][pos])
				adj[i][pos] = INF, Q.push(i);
	}

}
int main()
{
	while (1)
	{
		int m, start, end;
		long long min;
		scanf("%d %d", &n, &m);
		if (n == 0)
			break;

		initAdj();
		scanf("%d %d", &start, &end);
		while (m--)
		{
			int s, e;
			long long c;
			scanf("%d %d %lld", &s, &e, &c);
			adj[s][e] = c;
		}

		djstra(start);
		if (dist[end] == INF)
		{
			printf("-1\n");
			continue;
		}

		min = dist[end];
		deleteRoot(end, min);
		djstra(start);

		if (dist[end] == INF)
			printf("-1\n");

		else
			printf("%lld\n", dist[end]);
	}
}