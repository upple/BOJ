#include<cstdio>
#include<vector>
using namespace std;

int main()
{
	int n, k, b, count=0, max=0;
	scanf("%d %d %d", &n, &k, &b);
	vector<int> arr(n + 1, 1);

	while (b--)
	{
		int temp;
		scanf("%d", &temp);
		arr[temp] = 0;
	}

	for (int i = 1; i <= k; i++)
		count += arr[i];

	max = count;
	for (int i = 2; i + k - 1 <= n; i++)
	{
		count += arr[i + k - 1] - arr[i - 1];
		max = max > count ? max : count;
	}

	printf("%d", k - max);
}