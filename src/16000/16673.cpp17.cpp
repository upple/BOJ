#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long c, k, p;
    cin>>c>>k>>p;

    long long ans=0;
    for(int i=1; i<=c; i++)
        ans+=k*i+p*i*i;

    cout<<ans;
}