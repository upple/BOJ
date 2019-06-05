#include<cstdio>
#include<vector>
using namespace std;

bool dfs(vector<int> &M, vector<vector<int> > &adj, int c, int pos)
{
    M[pos]=c;
    for(auto i : adj[pos])
    {
        if(M[i]==M[pos])
            return true;

        else if(M[i]==-1 && dfs(M, adj, (c+1)%2, i))
            return true;
    }

    return false;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int v, e;
        scanf("%d %d", &v, &e);
        vector<vector<int> > adj(v+1);
        vector<int> M(v+1, -1);
        while(e--)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for(int i=1; i<=v; i++)
        {
            if(M[i]==-1&&dfs(M, adj, 1, i))
            {
                printf("NO\n");
                break;
            }

            if(i==v)
                printf("YES\n");
        }
    }
}
