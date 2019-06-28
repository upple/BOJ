#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[1000001], psum[1000001];
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;

    ll l=1, r=0, u=n*n;
    for(int i=1; i<=u; i++)
    {
        cin>>arr[i];
        r=max(r, arr[i]);
    }

    sort(arr+1, arr+u+1);

    for(int i=1; i<=u; i++)
        psum[i]=psum[i-1]+arr[i];

    ll ans=r;
    while(l<=r)
    {
        ll mid=l+r>>1;

        int idx=lower_bound(arr, arr+u+1, mid)-arr;
        ll tsum=(u-idx+1)*mid+psum[idx-1];
        if(tsum*2>=psum[u])
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }

    cout<<ans;
}