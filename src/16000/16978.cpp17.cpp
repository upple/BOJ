#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> pii;
struct q2{int idx, i, j, k;};
inline bool operator <(const q2 &a, const q2 &b)
{
    return a.k<b.k;
}
pii query1[100000];
q2 query2[100000];
int q1size, q2size;
ll pt[100001], arr[100001];
ll ans[100001];
int n;

void update(int p, ll x)
{
    while(p<=n)
    {
        pt[p]+=x;
        p+=p&-p;
    }
}

ll query(int p)
{
    ll ret=0;
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
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
        update(i, arr[i]);
    }

    int m;
    cin>>m;

    while(m--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int a;
            ll b;
            cin>>a>>b;
            query1[q1size++]={a, b};
        }
        else
        {
            int k, i, j;
            cin>>k>>i>>j;
            query2[q2size]={q2size, i, j, k};
            q2size++;
        }
    }

    sort(query2, query2+q2size);
    int progress=0;
    for(int i=0; i<q2size; i++)
    {
        auto &[idx, l, r, c]=query2[i];
        for(; progress<c; progress++)
        {
            auto &[p, x]=query1[progress];
            ll diff=x-arr[p];
            arr[p]=x;
            update(p, diff);
        }

        ans[idx]=query(r)-query(l-1);
    }

    for(int i=0; i<q2size; i++)
    {
        cout<<ans[i]<<'\n';
    }
}