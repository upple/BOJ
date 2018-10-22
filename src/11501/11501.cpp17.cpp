#include <bits/stdc++.h>
using namespace std;

int st[4000000], s;

int init(int x)
{
	if(x>=s) return st[x];
	return st[x]=max(init(x<<1), init((x<<1)+1));
}

int query(int l, int r, int p, int x, int y)
{
	if(x>r || y<l) return 0;
	if(x>=l && y<=r) return st[p];
	int mid=(x+y)>>1;
	return max(query(l, r, p<<1, x, mid), query(l, r, (p<<1)+1, mid+1, y));
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		s=1<<int(ceil(log2(n)));
		memset(st, 0, sizeof(st));
		for(int i=0; i<n; i++)
		{
			cin>>st[s+i];
		}

		init(1);

		long long ans=0, cnt=0;
		for(int i=0; i<n; i++)
		{
			int max_value=query(i, s-1, 1, 0, s-1);
			if(st[s+i]==max_value)
				ans+=(long long)cnt*st[s+i], cnt=0;

			else
				cnt++, ans-=st[s+i];

		}

		cout<<ans<<"\n";
	}
}