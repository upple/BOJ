#include <cstdio>
#include <queue>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, m, k, arr[100000], ans=0, cur=0;
		scanf("%d %d %d", &n, &m, &k);

		for(int i=0; i<n; i++)
			scanf("%d", &arr[i]);

		for(int i=0; i<m; i++)
			cur+=arr[i];

		if(cur<k)
			ans++;

		if(n==m)
			goto jump;
		for(int i=(m%n); i!=m-1; i=(i+1)%n)
		{
			cur+=arr[i]; cur-=arr[(i+n-m)%n];
			if(cur<k)
				ans++;
		}

		jump:
		printf("%d\n", ans);
	}

}
