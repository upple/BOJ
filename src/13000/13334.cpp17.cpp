#include <bits/stdc++.h>
#define MAX 100001
using namespace std;
typedef long long ll;
int pt[MAX], n;
ll d[MAX];
pair<ll, ll> arr[MAX];

void update(int p, int x)
{
    while(p<=n)
    {
        pt[p]+=x;
        p+=p&-p;
    }
}

int query(int p)
{
    int ret=0;
    while(p)
    {
        ret+=pt[p];
        p-=p&-p;
    }

    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        ll a, b;
        cin>>a>>b;
        if(a>b) swap(a, b);
        arr[i]={b, a};
        d[i]=a;
    }

    int k;
    cin>>k;
    sort(d, d+n);
    sort(arr, arr+n);
    int ans=0;
    for(int i=0; i<n; i++)
    {
        int it=lower_bound(d, d+n, arr[i].second)-d;
        int l=lower_bound(d, d+n, arr[i].first-k)-d;
        update(it+1, 1);
        ans=max(ans, i+1-query(l));
    }

    cout<<ans;
}