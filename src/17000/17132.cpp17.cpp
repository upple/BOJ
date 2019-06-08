#include <bits/stdc++.h>
using namespace std;
const int MAX=100001;
int n;
struct edge{int u, v, w;};
bool operator <(const edge &a, const edge &b)
{
    return a.w>b.w;
}
int s[MAX], l[MAX], p[MAX];
vector<edge> arr;

int Find(int x)
{
    if(x==p[x]) return x;
    return p[x]=Find(p[x]);
}

void Union(int a, int b, int w)
{
    s[a]+=s[b];
    l[a]=w;
    p[b]=a;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=1; i<=n; i++)
        p[i]=i, s[i]=1;

    while(--n)
    {
        int u, v, w;
        cin>>u>>v>>w;
        arr.push_back({u, v, w});
    }

    sort(arr.begin(), arr.end());
    long long ans=0;
    for(auto &[u, v, w] : arr)
    {
        int a=Find(u), b=Find(v);
        ans+=(long long)w*s[a]*s[b];
        Union(a, b, w);
    }

    cout<<ans;
}