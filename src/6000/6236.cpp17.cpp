#include <bits/stdc++.h>
using namespace std;

int arr[100000];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, l=0, r=1e9, ans=1e9;
	cin>>n>>m;
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
		l=max(l, arr[i]);
	}

	while(l<=r)
	{
		int mid=(l+r)>>1;
		int cur=0, cnt=0;
		for(int i=0; i<n; i++)
		{
			if(arr[i]>cur)
			{
				cnt++;
				cur=mid;
			}
			cur-=arr[i];
			if(cnt>m) break;
		}

		if(cnt>m)
		{
			l=mid+1;
		}
		else
		{
			ans=min(ans, mid);
			r=mid-1;
		}
	}

	cout<<ans;
}