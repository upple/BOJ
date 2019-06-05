#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_set<ll> A, B;

int main()
{
    int n, m;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        ll x, y;
        cin>>x>>y;
        A.insert((x<<20) | y);
    }

    cin>>m;
    for(int i=0; i<m; i++)
    {
        ll x, y;
        cin>>x>>y;
        B.insert((x<<20) | y);
    }

    for(ll cur : B)
    {
        ll diff=cur-*A.begin();
        bool flag=true;
        for(ll i : A)
        {
            if(B.find(i+diff)==B.end())
            {
                flag=false;
                break;
            }
        }

        if(flag==true)
        {
            int a=(cur>>20), b=(cur & 0xfffffLL);
            int c=(*A.begin()>>20), d=(*A.begin() & 0xfffffLL);
            cout<<a-c<<' '<<b-d;
            return 0;
        }
    }
}
