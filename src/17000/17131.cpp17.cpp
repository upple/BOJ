#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int pt[400002];
map<int, vector<int> > S;
const int MAX=400001;
const ll MOD=1e9+7;
int n;

void update(int p)
{
    while(p<=MAX)
    {
        if(++pt[p]>=MOD) pt[p]-=MOD;
        p+=p&(-p);
    }
}

ll query(int p)
{
    ll ret=0;
    while(p)
    {
        ret+=pt[p];
        p-=p&(-p);
    }

    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;

    for(int i=0; i<n; i++)
    {
        int x, y;
        cin>>x>>y;
        S[y].push_back(x+200001);
    }

    ll ans=0;
    ll sum=0;
    for(auto it=S.rbegin(); it!=S.rend(); it++)
    {
        vector<int> &v=it->second;
        for(int cur : v)
        {
            ans=(ans+query(cur-1)*(sum-query(cur)))%MOD;
        }

        sum+=v.size();
        for(int cur : v)
            update(cur);
    }

    cout<<ans;

}