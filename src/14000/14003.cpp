#include <cstdio>
#include <algorithm>
int arr[1000011], p[1000011], ans[1000001];
int len = 1;
int main()
{
	int n;
	scanf("%d %d", &n, &arr[0]);
	ans[0] = arr[0];
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &arr[i]);
		int it = std::lower_bound(ans, ans + len, arr[i]) - ans;
		p[i] = it;
		ans[it] = arr[i];
		if(it==len)
			len++;
	}

	printf("%d\n", len);
	int c = len - 1;
	for (int i = n - 1; i >= 0; i--)
		if (p[i] == c) ans[c] = arr[i], c--;
    
	for (int i = 0; i < len; i++)
		printf("%d ", ans[i]);
}