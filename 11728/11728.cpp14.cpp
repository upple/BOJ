#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);

	int it_a = 0, it_b = 0;
	while (it_a != n || it_b != m)
	{
		if (it_a == n)
			printf("%d ", b[it_b++]);

		else if (it_b == m)
			printf("%d ", a[it_a++]);

		else
			printf("%d ", (a[it_a] > b[it_b] ? b[it_b++] : a[it_a++]));
	}
}