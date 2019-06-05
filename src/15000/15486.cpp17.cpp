#include <bits/stdc++.h>

int arr[1500001], n, ans;
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		int t, p;
		scanf("%d %d", &t, &p);
		arr[i]=std::max(arr[i-1], arr[i]);
		if(i+t<=n+1)
		{
			arr[i+t]=std::max(arr[i+t], arr[i]+p);
			ans=std::max(ans, arr[i+t]);
		}

	}

	printf("%d", ans);
}
