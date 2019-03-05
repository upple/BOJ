#include <iostream>
#include <cmath>
#include <algorithm>
#define MAX 1000000
using namespace std;
typedef long long ll;
ll tree[4*MAX];
int n, m, s;

void update(int p, ll x)
{
	p+=s;
	x=x-tree[p];
	while(p)
	{
		tree[p]+=x;
		p>>=1;
	}
}

ll sum(int l, int r, int p, int x, int y)
{
	if(l>y || r<x) return 0;
	if(l<=x && r>=y) return tree[p];
	int mid=(x+y)>>1;
	return sum(l, r, p<<1, x, mid)+sum(l, r, (p<<1)+1, mid+1, y);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	s=1<<int(ceil(log2(n)));
	while(m--)
	{
		int c, a, b;
		cin>>c>>a>>b;
		if(c==0) cout<<sum(min(a, b)-1, max(a, b)-1, 1, 0, s-1)<<"\n";
		else update(a-1, (ll)b);
	}
}
