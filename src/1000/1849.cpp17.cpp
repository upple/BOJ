#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int tree[4*MAX], result[MAX];
int n, s;

int init(int p)
{
	if(p>=s) return tree[p]=1;
	return tree[p]=init(p<<1)+init((p<<1)+1);
}

void update(int p)
{
	p+=s;
	while(p)
	{
		tree[p]-=1;
		p>>=1;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;
	s=1<<int(ceil(log2(n)));
	init(1);
	for(int i=1; i<=n; i++)
	{
		int x;
		cin>>x;
		int l=1, r=s, p=1;
		x++;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(tree[p<<1]>=x) 
			{
				r=mid;
				p<<=1;
			}
			else
			{
				l=mid+1;
				x-=tree[p<<1];
				p=(p<<1)+1;
			} 
		}
		result[l]=i;
		update(l-1);
	}

	for(int i=1; i<=n; i++)
		cout<<result[i]<<"\n";
}