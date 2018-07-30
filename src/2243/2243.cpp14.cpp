#include <iostream>
#include <cmath>
#define MAX 1000001
using namespace std;

int st[4*MAX];
int n, s;

void update(int p, int x)
{
	p+=s;
	while(p)
	{
		st[p]+=x;
		p>>=1;
	}
}

int query(int l, int r, int p, int x, int y)
{
	if(l>y || r<x) return 0;
	if(l<=x && r>=y) return st[p];
	int mid=(x+y)>>1;
	return query(l, r, p<<1, x, mid)+query(l, r, (p<<1)+1, mid+1, y);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
	cin>>n;
	s=1<<int(ceil(log2(MAX)));
	
	for(int i=0; i<n; i++)
	{
		int a, b, c;
		cin>>a>>b;
		if(a==1)
		{
			int l=1, r=MAX-1;
			int mid=(l+r)>>1;
			while(l<=r)
			{
				int cnt=query(0, mid, 1, 0, s-1);
				if(cnt<b)
				{
					l=mid+1;
				}
				else
				{
					if(cnt-st[s+mid]>=b)
					{
						r=mid-1;
					}
					else
					{
						break;
					}
				}
				
				mid=(l+r)>>1;
			}
			
			cout<<mid<<"\n";
			update(mid, -1);
		}
		else
		{
			cin>>c;
			update(b, c);
		}
	}
}