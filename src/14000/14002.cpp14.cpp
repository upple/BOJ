#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int p[1001] = {};
int arr[1001], ans[1001] = {};
void printLIS(int num, int pos)
{
	if (pos==-1)
		return;

	if (p[pos] == num)
	{
		printLIS(num - 1, pos - 1);
		printf("%d ", arr[pos]);
	}

	else
		printLIS(num, pos - 1);

}
int main()
{
	int size = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		auto it = lower_bound(ans, ans+size+1, arr[i]);
		if (it == ans + size + 1)
			size++;
		*it = arr[i];

		p[i] = it - ans;

	}
	printf("%d\n", size);
	printLIS(size, n-1);
}