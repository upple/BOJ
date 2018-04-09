#include<cstdio>
#include<queue>

using namespace std;

bool adj[1001][1001] = { 0, };

int no_node;
void dfs(int n)
{
	static int count = 1;
	static bool visit[1001] = { 0, };
	visit[n] = true;
	printf("%d ", n);
	if (count >= no_node)
		return;

	for (int i = 1; i <= no_node; i++)
	{
		if (adj[n][i] == true && !visit[i])
			count++, dfs(i);
	}
}

void bfs(int n)
{
	queue<int> Queue;
	bool visit[1001] = { 0, };
	Queue.push(n);
	visit[n] = true;
	printf("%d ", n);
	while (!Queue.empty())
	{
		int pos = Queue.front();
		Queue.pop();
		for(int i=1; i<=no_node; i++)
			if (visit[i] == false && adj[pos][i] == true)
				visit[i] = true, Queue.push(i), printf("%d ", i);

	}
}

int main()
{
	int no_edge, start, a, b;
	scanf("%d %d %d", &no_node, &no_edge, &start);

	for (int i = 0; i < no_edge; i++)
	{
		scanf("%d %d", &a, &b);
		adj[b][a] = adj[a][b] = true;
		
	}

	dfs(start);
	printf("\n");
	bfs(start);
	return 0;
}