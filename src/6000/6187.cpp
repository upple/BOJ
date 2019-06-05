#include <cstdio>
#include <algorithm>
int c, m;
int arr[20];

int solve(int x, int it)
{
	if(x>c)
		return -arr[it-1];

	if(it==m)
		return 0;

	return std::max(solve(x, it+1), arr[it]+solve(x+arr[it], it+1));
}
int main()
{
	scanf("%d %d", &c, &m);

	for(int i=0; i<m; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("%d", solve(0, 0));
}
