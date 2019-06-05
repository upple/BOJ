#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int n, m;
	int basket[101];
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		basket[i]=i;

	for (int i = 0; i < m; i++)
	{
		int start, end;
		scanf("%d %d", &start, &end);
		swap(basket[start], basket[end]);
	}

	for (int i = 1; i <= n; i++)
		printf("%d ", basket[i]);

	printf("\n");
	return 0;
}
