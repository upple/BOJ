#include <iostream>
#include <algorithm>
using namespace std;
int n;
int s[8], w[8];

int solve(int p, int c)
{
    int ans=c;
    if(p==n) return c;
    if(s[p]<=0) return solve(p+1, c);
    for(int i=0; i<n; i++)
    {
        if(i==p) continue;
        if(s[i]<=0) continue;
        s[i]-=w[p];
        s[p]-=w[i];
        ans=max(ans, solve(p+1, c+(s[i]<=0)+(s[p]<=0)));
        s[i]+=w[p];
        s[p]+=w[i];
    }

    return ans;
}
int main()
{
    cin>>n;

    for(int i=0; i<n; i++)
        cin>>s[i]>>w[i];

    cout<<solve(0, 0);
}