#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

struct edge {int a, b, c;};
bool operator <(const edge &a, const edge &b)
{
    return a.c>b.c;
}

int parent[MAX];

int Find(int x)
{
    if(x==parent[x]) return x;
    return parent[x]=Find(parent[x]);
}

bool Union(edge &x)
{
    int a=Find(x.a);
    int b=Find(x.b);
    if(a==b) return false;
    
    if(parent[a]>parent[b]) swap(a, b);
    parent[b]=parent[a];
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int minimum_cost=0, remain, n, m; 
    cin>>n>>m;

    priority_queue<edge> pq;
    while(m--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        pq.push({a, b, c});
    }

    for(int i=1; i<=n; i++) 
        parent[i]=i;

    remain=n-1;
    while(remain)
    {
        edge cur=pq.top();
        pq.pop();
        if(!Union(cur)) continue;
        minimum_cost+=cur.c;
        remain--;
    }

    cout<<minimum_cost;
}