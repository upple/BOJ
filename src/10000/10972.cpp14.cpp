#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int n, *arr;
	scanf("%d", &n);
	arr = new int[n];

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	if (next_permutation(arr, arr + n))
		for (int i = 0; i < n; i++)
			printf("%d ", arr[i]);

	else
		printf("-1");

	delete[] arr;
}