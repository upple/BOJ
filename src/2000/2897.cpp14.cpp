#include <cstdio>
using namespace std;
int main()
{
    int n, m, num[5]={};
    char adj[50][51]={};
    int dx[]={0, 0, 1, 1}, dy[]={0, 1, 0, 1};
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++)
        scanf("%s", adj[i]);

    for(int i=0; i<n-1; i++)
        for(int j=0; j<m-1; j++)
        {
            int no_car=0, bdg=0;
            for(int k=0; k<4; k++)
            {
                if(adj[i+dx[k]][j+dy[k]]=='X')
                    no_car++;

                else if(adj[i+dx[k]][j+dy[k]]=='#')
                    bdg=1;
            }
            if(bdg)
                continue;

            num[no_car]++;
        }

    for(int i=0; i<5; i++)
        printf("%d\n", num[i]);
}
