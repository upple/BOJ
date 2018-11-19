#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int> > edge;
priority_queue<edge> pq;
int p[1001];

int Find(int a)
{
    if(p[a]==a) return a;
    return p[a]=Find(p[a]);
}

bool Union(edge e)
{
    int a=e.second.first, b=e.second.second;
    int pa=Find(a), pb=Find(b);
    if(pa==pb) return false;
    p[pb]=pa;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        p[i]=i;
        for(int j=1;j<=n; j++)
        {
            int x;
            cin>>x;
            if(i<j)
                pq.push({-x, {i, j}});
        }
    }

    int remain=n-1, ans=0;
    while(remain>0)
    {
        edge e = pq.top();
        pq.pop();
        if(Union(e))
        {
            ans-=e.first;
            remain--;
        }
    }

    cout<<ans;
}