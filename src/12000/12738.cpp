#include <cstdio>
#include <algorithm>

int ans[1000001];
int main()
{
	int n, num, size = 1;
	scanf("%d %d", &n, ans);

	for (int i = 1; i < n; i++)
	{
		scanf("%d", &num);
		int *it = std::lower_bound(ans, ans + size, num);
		if (it == ans + size)
			size++;

		*it = num;
	}

	printf("%d", size);
}