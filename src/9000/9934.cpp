#include <cstdio>
#include <cmath>
int arr[1024];
int no[1024];
int k, s, c;

void solve(int x)
{
	if (x*2 > s)
	{
		arr[x] = no[++c];
		return;
	}

	solve(x * 2);
	arr[x] = no[++c];
	solve(x * 2 + 1);
}
int main()
{
	scanf("%d", &k);
	s = (1 << k) - 1;
	
	for (int i = 1; i <= s; i++)
	{
		scanf("%d", &no[i]);
	}

	solve(1);
	for (int i = 1, j=1; i <= s; i++, j++)
	{
		if (i - 1 && (i&-i) == i)
			printf("\n");
		printf("%d ", arr[i]);
	}
}