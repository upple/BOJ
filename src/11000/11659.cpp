#include<cstdio>

int main()
{
	int n, m, t;
	int arr[100001] = {};
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &t);
		arr[i] = arr[i - 1] + t;
	}
	while (m--)
	{
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", arr[e] - arr[s - 1]);
	}
}