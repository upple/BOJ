#include <bits/stdc++.h>
using namespace std;

int s[8], w[8];
int n;

int solve(int p, int c)
{
    if(p==n) return c;
    if(s[p]==0) return solve(p+1, c);
    int ret=c;
    for(int i=0; i<n; i++)
    {
        if(s[i]==0 || i==p) continue;
        int ps[2]={s[i], s[p]};
        s[i]=max(0, s[i]-w[p]);
        s[p]=max(0, s[p]-w[i]);
        ret=max(ret, solve(p+1, c+(s[i]==0)+(s[p]==0)));
        s[i]=ps[0];
        s[p]=ps[1];
    }
    return ret;
}
int main()
{
    cin>>n;

    for(int i=0; i<8; i++)
        cin>>s[i]>>w[i];

    cout<<solve(0, 0);
}