#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int> > adj;
vector<int> p;
void findParents(int k)
{
    for(auto i : adj[k])
        if(!p[i])
            p[i]=k, findParents(i);
}
int main()
{
    int n;
    scanf("%d", &n);
    adj.resize(n+1), p.resize(n+1);
    for(int i=0; i<n-1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    p[1]=-1;
    findParents(1);
    for(int i=2; i<=n; i++)
        printf("%d\n", p[i]);

}
