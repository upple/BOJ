#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
ll f[4000001];

ll power(ll x, ll n)
{
    ll ret=1;

    while(n)
    {
        if(n%2) ret=(ret*x)%MOD;
        x=(x*x)%MOD;
        n>>=1;
    }

    return ret;
}
int main()
{
    int n, k;
    f[0]=1;
    cin>>n>>k;

    for(int i=1; i<=n; i++)
        f[i]=(f[i-1]*i)%MOD;

    cout<<f[n]*power(f[k]*f[n-k]%MOD, MOD-2)%MOD;
}