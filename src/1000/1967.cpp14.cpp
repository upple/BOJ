#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
vector<vector<pair<int, int> > > adj;
vector<int> d;
int n;

int bfs(int a)
{
    int max=0;
    vector<bool> v(n+1);
    queue<int> Q;
    v[a]=true, d[a]=0;
    Q.push(a);
    while(!Q.empty())
    {
        int pos=Q.front();
        Q.pop();
        for(auto i : adj[pos])
            if(!v[i.first])
            {
                v[i.first]=true, d[i.first]=d[pos]+i.second;
                Q.push(i.first);
                if(d[max]<d[i.first])
                    max=i.first;
            }

    }
    return max;
}
int main()
{
    scanf("%d", &n);
    adj.resize(n+1), d.resize(n+1);
    for(int i=1; i<n; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    printf("%d", d[bfs(bfs(1))]);
}
