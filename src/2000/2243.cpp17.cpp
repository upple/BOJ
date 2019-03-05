#include <bits/stdc++.h>
using namespace std;

int tree[1000001];

void update(int p, int x)
{
    while(p<=1000000)
    {
        tree[p]+=x;
        p+=p&-p;
    }
}

int query(int p)
{
    int ret=0;
    while(p)
    {
        ret+=tree[p];
        p-=p&-p;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, max_=1;
    cin>>n;
    while(n--)
    {
        int a, b, c;
        cin>>a>>b;
        if(a==1)
        {
            int l=1, r=max_, ans=1e9;
            while(l<=r)
            {
                int mid=l+r>>1;
                int ret=query(mid);

                if(ret>=b)
                {
                    ans=min(ans, mid);
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
                
            }

            cout<<ans<<'\n';
            update(ans, -1);
        }

        else
        {
            cin>>c;
            max_=max(max_, b);
            update(b, c);
        }
        
    }
}