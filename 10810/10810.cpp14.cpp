#include<cstdio>
using namespace std;

const long long INF = 999999999;
const int MAX_NODE = 801;
int main()
{
	int n, m;
	int basket[101] = { 0, };

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int start, end, no;
		scanf("%d %d %d", &start, &end, &no);
		for (int j = start; j <= end; j++)
			basket[j] = no;
	}

	for (int i = 1; i <= n; i++)
		printf("%d ", basket[i]);

	printf("\n");
	return 0;
}
