#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
	int n, k, ans=0;
	scanf("%d %d", &n, &k);
	vector<int> arr(n);
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	for(int i=n-1; i>=0; i--)
	{
		ans+=k/arr[i];
		k%=arr[i];
	}

	printf("%d", ans);

}
