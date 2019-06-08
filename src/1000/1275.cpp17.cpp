#include <bits/stdc++.h>
#define MAX 100000
using namespace std;
typedef long long ll;
ll tree[MAX*4];
int n, q, s;

long long init(int p)
{
    if(p>=s) return tree[p];
    return tree[p]=init(p<<1)+init((p<<1)+1); 
}

void update(int p, long long x)
{
    p+=s;
    x-=tree[p];
    while(p)
    {
        tree[p]+=x;
        p>>=1;
    }
}

long long query(int l, int r, int p, int x, int y)
{
    if(l>y || r<x) return 0;
    if(l<=x && r>=y) return tree[p];
    int mid=x+y>>1;
    return query(l, r, p<<1, x, mid)+query(l, r, (p<<1)+1, mid+1, y);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>q;
    s=1<<int(ceil(log2(n)));
    for(int i=0; i<n; i++)
        cin>>tree[s+i];

    init(1);
    while(q--)
    {
        ll x, y, a, b;
        cin>>x>>y>>a>>b;

        if(x>y) swap(x, y);
        cout<<query(x-1, y-1, 1, 0, s-1)<<'\n';
        update(a-1, b);
    }
}