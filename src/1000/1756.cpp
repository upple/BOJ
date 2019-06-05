#include <cstdio>
#include <algorithm>
int arr[300001];
int main()
{
	int d, n;
	scanf("%d %d", &d, &n);
	arr[d]=1111111111;
	for(int i=d-1; i>=0; i--)
	{
		scanf("%d", &arr[i]);
		if(arr[i+1]<arr[i]) arr[i]=arr[i+1];
	}

	int p=-1;
	while(n--)
	{
		int x;
		scanf("%d", &x);
		while(++p<d)
		{
			if(arr[p]>=x) break;
		}
	}
	printf("%d", std::max(d-p, 0));
}
