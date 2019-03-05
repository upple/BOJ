#include<cstdio>
#include<vector>
using namespace std;

vector<vector<int> > adj;
vector<bool>visit;

void dfs(int s)
{
    for(auto i : adj[s])
    {
        if(!visit[i])
            visit[i]=true, dfs(i);
    }
}
int main()
{
    int N, E, ans=0;
    scanf("%d %d", &N, &E);

    adj.resize(N+1), visit.resize(N+1);
    while(E--)
    {
        int s, e;
        scanf("%d %d", &s, &e);
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    for(int i=1; i<=N; i++)
    {
        if(!visit[i])
            ans++, visit[i]=true, dfs(i);
    }

    printf("%d\n", ans);
}
