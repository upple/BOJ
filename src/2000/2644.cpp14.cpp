#include <cstdio>

using namespace std;

const int MAX_SIZE = 101;
const int INF = 101010;
int main(void)
{
	int arr[MAX_SIZE][MAX_SIZE];
	int dist[MAX_SIZE];
	int no_p, no_edge;
	int start, end;
	int son, dad;
	scanf("%d %d %d %d", &no_p, &start, &end, &no_edge);
	for (int i = 1; i <= no_p; i++)
	{
		for (int j = 1; j <= no_p; j++)
			arr[i][j] = INF;

		dist[i] = INF;
		arr[i][i] = 0;
	}

	for (int i = 0; i < no_edge; i++)
	{
		scanf("%d %d", &son, &dad);
		arr[son][dad] = 1;
		arr[dad][son] = 1;
	}
	dist[start] = 0;

	for(int k=1; k<=no_p; k++)
		for (int i = 1; i <= no_p; i++)
			for (int j = 1; j <= no_p; j++)
				if (dist[i] > dist[j] + arr[j][i])
					dist[i] = dist[j] + arr[j][i];


	if (dist[end] == INF)
		printf("-1\n");

	else
		printf("%d\n", dist[end]);
	
	return 0;
}