#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, num;
	int arr[500000];
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr+n);
	scanf("%d", &m);
	for(int i=0; i<m; i++)
	{
		scanf("%d", &num);
		printf("%d ", upper_bound(arr, arr+n, num)-lower_bound(arr, arr+n, num));
	}
	return 0;
}
