#include <bits/stdc++.h>
#define MAX 5000000
#define INF 1e9
using namespace std;

int st[4*MAX];
int n, l, s;

int init(int x)
{
	if(x>=s) return st[x];
	return st[x]=min(init(x<<1), init((x<<1)+1));
}

int query(int l, int r, int p, int x, int y)
{
	if(l>y || r<x) return INF;
	if(l<=x && r>=y) return st[p];
	int mid=(x+y)>>1;
	return min(query(l, r, p<<1, x, mid), query(l, r, (p<<1)+1, mid+1, y));
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>l;
	s=1<<int(ceil(log2(n)));
	for(int i=0; i<n; i++)
		cin>>st[s+i];

	init(1);
	for(int i=0; i<n; i++)
		cout<<query(max(0, i-l+1), i, 1, 0, s-1)<<" ";
}