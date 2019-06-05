#include<cstdio>
#define min(x, y) (x<y?x:y)
#define INF 55555555
using namespace std;

int main()
{
    int V, E, ans=INF;
    int adj[401][401]={};
    scanf("%d %d", &V, &E);

    for(int i=1; i<=V; i++)
        for(int j=1; j<=V; j++)
            adj[i][j]=INF;

    while(E--)
    {
        int s, e, c;
        scanf("%d %d %d", &s, &e, &c);

        adj[s][e]=c;
    }

    for(int k=1; k<=V; k++)
        for(int i=1; i<=V; i++)
            for(int j=1; j<=V; j++)
                if(adj[i][j]>adj[i][k]+adj[k][j])
                    adj[i][j]=adj[i][k]+adj[k][j];

    for(int i=1; i<=V; i++)
        ans=min(ans, adj[i][i]);

    if(ans==INF)
        printf("-1\n");

    else
        printf("%d", ans);
}
