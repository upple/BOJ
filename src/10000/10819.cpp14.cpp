#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int n, ans=0;
	scanf("%d", &n);
	vector<int> arr(n);
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	sort(arr.begin(), arr.end());
	do
	{
		int sum=0;
		for(int i=0; i<n-1; i++)
			sum+=abs(arr[i]-arr[i+1]);

		ans=max(ans, sum);
	} while(next_permutation(arr.begin(), arr.end()));

	printf("%d\n", ans);
}
