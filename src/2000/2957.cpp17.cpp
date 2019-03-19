#include <bits/stdc++.h>
using namespace std;

int p[300001][20];
int d[300001];
int n;
set<int> S;

int lca(int a, int b)
{
    if(d[a]>d[b]) swap(a, b);
    int diff=d[b]-d[a];
    for(int i=0; i<20; i++)
    {
        if(diff & (1<<i))
        {
            b=p[b][i];
        }
    }

    if(a==b) return a;
    for(int i=20; i--;)
    {
        if(p[a][i]!=p[b][i])
        {
            a=p[a][i];
            b=p[b][i];
        }
    }

    return p[a][0];
}
long long insert(int x)
{
    static long long c=0;

    auto hi=S.upper_bound(x);
    if(hi==S.end())
    {
        d[x]=d[*(--hi)]+1;
        p[x][0]=*hi;
    }
    else if(hi==S.begin())
    {
        d[x]=d[*hi]+1;
        p[x][0]=*hi;
    }
    else
    {
        auto lo=(--hi)++;
        int po=lca(*lo, *hi);
        auto par=S.begin();
        if(po>x) par=lo;
        else par=hi;

        d[x]=d[*par]+1;
        p[x][0]=*par;
    }
    
    for(int i=1; i<20; i++)
    {
        p[x][i]=p[p[x][i-1]][i-1];
        if(p[x][i]==0) break;
    }

    S.insert(x);
    return c+=d[x]-1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x;
    cin>>n>>x;
    S.insert(x);
    d[x]=1;
    cout<<0<<'\n';
    while(--n)
    {
        int x;
        cin>>x;
        cout<<insert(x)<<'\n';
    }
}