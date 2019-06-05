#include <bits/stdc++.h>
using namespace std;

set<int> S;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	int a, b, k, m;
	cin>>a>>b>>k>>m;
	int max_y=0;
	while(m--)
	{
		int x, y;
		cin>>y>>x;
		max_y=max(max_y, y);
		S.insert(x);
	}

	int l=max_y, r=a;
	int ans=1e9;
	while(l<=r)
	{
		int mid=(l+r)>>1, cnt=1;
		auto it=S.begin();
		int s=*it;
		for(;it!=S.end(); it++)
		{
			if(*it-s>=mid)
			{
				cnt++;
				s=*it;
			}
		}

		if(cnt>k)
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