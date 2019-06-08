#include <cstdio>
#include <algorithm>
typedef long long ll;
int main()
{
	int n;
	ll arr[10000], ans=0, temp=0;
	scanf("%d", &n);

	for(int i=0; i<n; i++)
		scanf("%lld", &arr[i]);

	std::sort(arr, arr+n);
	for(int i=1; i<n; i++)
	{
		temp+=(arr[i]-arr[i-1])*i;
		ans+=temp;
	}

	printf("%lld", ans*2);
}
