#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct room
{
    ll t, a, h;
};

room arr[130000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, h;
    cin>>n>>h;

    ll l=0, r=0;

    for(ll i=0; i<n; i++)
    {
        ll t, a, h;
        cin>>t>>a>>h;
        if(t==1)
        {
            r+=a*h;
        }
        arr[i]={t, a, h};
    }

    r=r/h+1;
    ll ans=r;
    while(l<=r)
    {
        ll max_health=(l+r)>>1, cur=max_health;
        ll atk=h;
        bool chk=true;
        for(int i=0; i<n; i++)
        {
            if(arr[i].t==1)
            {
                if((arr[i].h/atk)+(arr[i].h%atk!=0)<=(cur/arr[i].a)+(cur%arr[i].a!=0))
                {
                    cur-=arr[i].a*(((arr[i].h/atk)+(arr[i].h%atk!=0))-1);
                }
                else
                {
                    chk=false;
                    break;
                }
            }
            else
            {
                cur=min(cur+arr[i].h, max_health);
                atk+=arr[i].a;
            }
        }

        if(chk==true)
        {
            r=max_health-1;
            ans=min(ans, max_health);
        }
        else l=max_health+1;
    }

    cout<<ans;
}