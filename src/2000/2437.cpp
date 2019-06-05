#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n, arr[1000], cur=0;
	scanf("%d", &n);

	for(int i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}

	sort(arr, arr+n);

	for(int i=0; i<n; i++)
	{
		if(cur+1<arr[i])
		{
			printf("%d", cur+1);
			return 0;
		}

		cur+=arr[i];
	}

	printf("%d", cur+1);
}
