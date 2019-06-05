#include <cstdio>
#include <algorithm>
using namespace std;

int ans[1000001];
int main()
{
	int n, num, size=0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		int *it = lower_bound(ans, ans + size + 1, num);
		if (it == ans + size + 1)
			size++;

		*it = num;
	}

	printf("%d", size);
}