#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	int A[20000], B[20000];
	scanf("%d", &t);

	while (t--)
	{
		int n, m, ans=0;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%d", &A[i]);

		for (int i = 0; i < m; i++)
			scanf("%d", &B[i]);

		sort(B, B + m);

		for (int i = 0; i < n; i++)
			ans += lower_bound(B, B + m, A[i])-B;

		printf("%d\n", ans);
	}
}