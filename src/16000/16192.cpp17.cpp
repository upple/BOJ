#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<ll, ll> point[2001];
vector<int> p;

ll get_dist(ll x1, ll y1, ll x2, ll y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin>>n>>q;

    for(int i=1; i<=n; i++)
    {
        cin>>point[i].first>>point[i].second;
    }

    while(q--)
    {
        ll mind=1000000000000000LL;
        int c=0;
        ll x, y;
        p.clear();
        cin>>x>>y;
        for(int i=1; i<=n; i++)
        {
            double ret=get_dist(point[i].first, point[i].second, x, y);
            if(mind>ret)
            {
                mind=ret;
                c=1;
                p.clear();
                p.push_back(i);
            }
            else if(mind==ret)
            {
                c++;
                if(p.size()<2) p.push_back(i);
            }
        }
        if(c==0)
        {
            cout<<"NONE\n";
        }
        else if(c==1)
        {
            cout<<"REGION "<<p[0]<<"\n";
        }
        else if(c==2)
        {
            cout<<"LINE "<<p[0]<<' '<<p[1]<<"\n";
        }
        else
        {
            cout<<"POINT\n";
        }
    }

    
}