#include <iostream>
#define MAX 1000000
using namespace std;

int n, q, c, s;
long long tree[4*MAX];
void update(int p, int x)
{
    p=c+p-1;
    while(p)
    {
        tree[p]+=x;
        p/=2;
    }
}

long long query(int l, int r, int p, int x, int y)
{
    if(y<l || x>r)
        return 0;

    if(l<=x && r>=y)
        return tree[p];

    long long mid = (x+y)>>1;
    return query(l, r, p*2, x, mid)+query(l, r, p*2+1, mid+1, y);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>q;
    c=n;
    if((c&-c)!=c)
    {
        while(c!=1) c>>=1, s++;
    }
    c<<=s+1;
    while(q--)
    {
        int a, p, x;
        cin>>a>>p>>x;
        if(a==1) update(p, x);

        else cout<<query(p-1, x-1, 1, 0, c-1)<<"\n";
    }
}