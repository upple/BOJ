#include <cstdio>

int arr[2][7];
int main()
{
	int n, k, s, y, ans = 0;
	scanf("%d %d", &n, &k);

	while (scanf("%d %d", &s, &y)!=EOF)
		arr[s][y]++;

	for (int i = 0; i < 2; i++)
		for (int j = 1; j <= 6; j++)
			ans += arr[i][j] / k + (arr[i][j] % k != 0);

	printf("%d", ans);
}