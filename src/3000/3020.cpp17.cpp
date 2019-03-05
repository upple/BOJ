#include <bits/stdc++.h>
using namespace std;

int f[2][100001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, h;
    cin>>n>>h;

    for(int i=0; i<n; i++)
    {
        cin>>f[i%2][i/2];
    }
    n>>=1;
    f[0][n]=f[1][n]=h;
    sort(f[0], f[0]+n);
    sort(f[1], f[1]+n);

    int ans=1e9, cnt=0;
    for(int i=1; i<=h; i++)
    {
        int ret=n-(upper_bound(f[0], f[0]+n, h-i)-f[0]);
        ret+=n-(upper_bound(f[1], f[1]+n, i-1)-f[1]);
        if(ans>ret)
        {
            ans=ret;
            cnt=1;
        }
        else if(ans==ret)
        {
            cnt++;
        }
    }

    cout<<ans<<' '<<cnt;
}